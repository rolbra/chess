#include <iostream>
#include <Windows.h>
#include <gdiplus.h>
#include "board.hpp"

#define BTN_OK 100
#define BTN_EXIT 101
#define IDM_BITMAP 200

static HWND sHwnd;
static Board board;

bool button_clicked = false;

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

    switch(message)
    {
    case WM_PAINT:
        SetWindowHandle(hwnd);
        hdc = BeginPaint( hwnd, &ps );

        board.drawFields( hdc );
        board.drawCharacter( hdc );
        board.drawSymbols( hdc );
        board.setSymbol( hdc, 0x77 );
        if( button_clicked )
        {
            board.setSelected( hdc, 0x34 );
            board.setSymbol( hdc, 0x34 );
        }
        
        EndPaint( hwnd, &ps );
        break;
    case WM_COMMAND:
        switch( LOWORD( wParam ) )
        {
            case BTN_OK:
                button_clicked = !button_clicked;
                InvalidateRect(hwnd, NULL, TRUE);
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
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           NULL,
                           NULL,
                           hInstance,
                           NULL);
    if(!hwnd)
    {
        MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);
        exit(0);
    }
    
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