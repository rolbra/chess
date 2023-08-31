// https://cplusplus.com/articles/Gw6AC542/

#include "drawer.hpp"
#include "player.hpp"
#include "input.hpp"
#include "splashScreen.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define BTN_OK 100
#define BTN_EXIT 101
#define BTN_SETUP 102
#define BTN_MOVE 103

#define IDM_BITMAP 200

#define TXT_USR_INPUT 300


static HWND sHwnd;
HWND output;
HWND hwndTxtUsrInput;
HWND slash;

static Drawer drawer;
static Player player0;
static Input input;
static SplashScreen splashScreen;

bool firstStart = true;
bool init = false;
bool button_ok = false;
bool button_setup = false;
bool button_move = false;

void SetWindowHandle(HWND hwnd)
{
    sHwnd=hwnd;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    
    static BITMAPINFOHEADER *pbmi = NULL;
    static BYTE *pBuffer = NULL;

    LPRECT invalidRect = new RECT();
    invalidRect->top = 0;
    invalidRect->left = 0;
    invalidRect->bottom = 600;
    invalidRect->right = 600;

    switch(message)
    {
    case WM_CREATE:
        output = CreateWindow("EDIT",
                                   "",
                                   WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   120, 530, 370, 20,
                                   hwnd, (HMENU) 1, NULL, NULL);
        break;
    case WM_PAINT:
        SetWindowHandle(hwnd);
        hdc = BeginPaint( hwnd, &ps );

        if( firstStart == true )
        {
            splashScreen.setPicture( L"..\\..\\PM\\bitmaps\\SplashScreens\\splash01.bmp" );
            splashScreen.show( hdc );
            firstStart = false;
        }

        drawer.board->drawBoard( hdc );
        if( button_setup == true )
        {
            drawer.board->initFigures();
            drawer.setFigures( hdc );
            button_setup = false;
        }
        if( button_move == true )
        {
            int len = GetWindowTextW( hwndTxtUsrInput, input.userInput, 64 );
            if( input.checkInputWChar() > 0 )
            {
                SetWindowTextW( output, input.userInput );
                break;
            }

            //SetWindowTextW( output, input.userInput );
            drawer.setFigures( hdc );
            button_move = false;
        }
        if( button_ok )
        {
            
        }
        
        EndPaint( hwnd, &ps );
        break;
    case WM_CHAR:
        case 0x0D: 
                    
            // Process a carriage return. 
            button_setup = true;
            InvalidateRect( hwnd, invalidRect, TRUE );
            break; 
    case WM_COMMAND:
        switch( LOWORD( wParam ) )
        {
            case BTN_OK:
                break;
            case BTN_SETUP:
                button_setup = true;
                InvalidateRect( hwnd, invalidRect, TRUE );
                break;
            case BTN_MOVE:
                button_move = true;
                InvalidateRect( hwnd, invalidRect, TRUE );
                break;
            case BTN_EXIT:
                PostQuitMessage(0);
                return 0;
            
        }
    case WM_CLOSE: // FAIL THROUGH to call DefWindowProc
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break; // FAIL to call DefWindowProc //
    }
    return DefWindowProc(hwnd,message,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow)
{
    //initialize GDI+
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup( &gdiplusToken, &gdiplusStartupInput, nullptr );

    static TCHAR szAppName[] = TEXT("chess");
    WNDCLASS wndclass;
    wndclass.style         = CS_HREDRAW|CS_VREDRAW ;
    wndclass.lpfnWndProc   = WndProc ;
    wndclass.cbClsExtra    = 0 ;
    wndclass.cbWndExtra    = 0 ;
    wndclass.hInstance     = hInstance ;
    wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
    wndclass.lpszMenuName  = NULL ;
    wndclass.lpszClassName = szAppName ;
// Register the window //
    if(!RegisterClass(& wndclass))
    {
        MessageBox(NULL,"Registering the class failled","Error",MB_OK|MB_ICONERROR);
        exit(0);
    }
// CreateWindow //
    HWND hwnd=CreateWindow(szAppName,"chess",
                           WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           WINDOW_WIDTH,
                           WINDOW_HEIGHT,
                           NULL,
                           NULL,
                           hInstance,
                           NULL);
    if(!hwnd)
    {
        MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);
        exit(0);
    }
    
    //Create Window for Splash Screen
    HWND hwndSplashScreen = CreateWindow(NULL,NULL,
                           WS_CHILD | WS_VISIBLE,
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           WINDOW_WIDTH,
                           WINDOW_HEIGHT,
                           NULL,
                           NULL,
                           hInstance,
                           NULL);

    //Create Button OK
    HWND hwndButtonOk = CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "OK",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    400,         // x position 
    500,         // y position 
    30,        // Button width
    20,        // Button height
    hwnd,     // Parent window
    ( HMENU ) BTN_OK,       // No menu.
    (HINSTANCE)GetWindowLongPtr( hwnd, GWLP_HINSTANCE ), 
    NULL);      // Pointer not needed.

    //Create Button Exit
    HWND hwndButtonExit = CreateWindow( 
    "BUTTON",
    "Exit",
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    450,
    500,
    30,
    20,
    hwnd,
    ( HMENU ) BTN_EXIT,
    (HINSTANCE)GetWindowLongPtr( hwnd, GWLP_HINSTANCE ), 
    NULL);

    //Create Button Setup
    HWND hwndButtonSetup = CreateWindow( 
    "BUTTON",
    "Setup",
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    250,
    500,
    50,
    20,
    hwnd,
    ( HMENU ) BTN_SETUP,
    (HINSTANCE)GetWindowLongPtr( hwnd, GWLP_HINSTANCE ), 
    NULL);

    //Create Button Setup
    HWND hwndButtonMove = CreateWindow( 
    "BUTTON",
    "Move",
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    300,
    500,
    50,
    20,
    hwnd,
    ( HMENU ) BTN_MOVE,
    (HINSTANCE)GetWindowLongPtr( hwnd, GWLP_HINSTANCE ), 
    NULL);

    hwndTxtUsrInput = CreateWindow("edit", "",
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
    50 ,530 ,50 ,20 ,
    hwnd, (HMENU) TXT_USR_INPUT, (HINSTANCE)GetWindowLongPtr( hwnd, GWLP_HINSTANCE ), NULL
    ); /* Text Input field */

// ShowWindow and UpdateWindow //
    ShowWindow(hwnd,iCmdShow);
    UpdateWindow(hwnd);
// Message Loop //
    MSG msg;
    while(GetMessage(& msg,NULL,0,0))
    {
        TranslateMessage(& msg);
        DispatchMessage(& msg);
    }

    Gdiplus::GdiplusShutdown( gdiplusToken );
    return 0;
}