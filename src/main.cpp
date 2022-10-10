#include <iostream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include "board.hpp"

#define CONSOLEBOARD

#ifdef CONSOLEBOARD

//===================TEST OPEN NEW CONSOLE==================
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    const char consoleTitle[6] = {'c','h','e','s','s','\0'};
    LPCSTR pConsoleTitle = consoleTitle;

    SetConsoleTitle( pConsoleTitle );

    HWND cmd = GetConsoleWindow();
    HDC hDC = GetDC(cmd);


    for( int r=100; r<200; r++)
    {
        for( int d=100; d<200; d++)
        {
            SetPixel(hDC, r, d, RGB(0xFF,0x00,0x00));
        }
    }

    ReleaseDC(cmd, hDC);
	DeleteDC(hDC);

    MSG msg;
    while(GetMessage(& msg,NULL,0,0))
    {
        TranslateMessage(& msg);
        DispatchMessage(& msg);
    }
    // use the console just like a normal one - printf(), getchar(), ...
}

#endif
//==========================================================

#ifdef GUIBOARD
//===================TEST CODE DRAWING PIXEL================
static HWND sHwnd;
static COLORREF redColor=RGB(255,0,0);
static COLORREF blueColor=RGB(0,0,255);
static COLORREF greenColor=RGB(0,255,0);

static COORD a = {150,150};
static COORD b = {300,300};

void SetWindowHandle(HWND hwnd)
{
    sHwnd=hwnd;
}
void setPixel(int x,int y,COLORREF& color=redColor)
{
    if(sHwnd==NULL)
    {
        MessageBox(NULL,"sHwnd was not initialized !","Error",MB_OK|MB_ICONERROR);
        exit(0);
    }
    HDC hdc=GetDC(sHwnd);
    SetPixel(hdc,x,y,color);
    ReleaseDC(sHwnd,hdc);
    return;
}
void drawStreightLine(COORD a, COORD b)
{
    for( int x = a.X; x < b.X; x++ )
    {
        setPixel(x, a.Y, greenColor);
    }
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    switch(message)
    {
    case WM_PAINT:
        SetWindowHandle(hwnd);
        drawStreightLine(a,b);
        break;
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
    static TCHAR szAppName[] = TEXT("Test");
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
    HWND hwnd=CreateWindow(szAppName,"SetPixel example - programming-technique.blogspot.com",
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
    return 0;
}

#endif