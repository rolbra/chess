#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include "board.hpp"

int main()
{
    std::cout << "\nHello Chess Player \n\n";

    Board chessBoard;

    //chessBoard.display();

    char positions[32];
    positions[0] = 0x44;

    /*
    Call c_str() to get a const char * (LPCSTR) from a std::string.

    It's all in the name:

    LPSTR - (long) pointer to string - char *

    LPCSTR - (long) pointer to constant string - const char *

    LPWSTR - (long) pointer to Unicode (wide) string - wchar_t *

    LPCWSTR - (long) pointer to constant Unicode (wide) string - const wchar_t *

    LPTSTR - (long) pointer to TCHAR (Unicode if UNICODE is defined, ANSI if not) string - TCHAR *

    LPCTSTR - (long) pointer to constant TCHAR string - const TCHAR *

    You can ignore the L (long) part of the names -- it's a holdover from 16-bit Windows.

    */
    const wchar_t myTw[3] = {'h','h','i'};    
    LPCWSTR newTitleW( myTw );
    SetConsoleTitle( newTitleW );

    HWND cmd = GetConsoleWindow();
    HDC hDC = GetDC(cmd);

    SetPixel(hDC, 100, 100, RGB(200,200,200));

    ReleaseDC(cmd, hDC);
	DeleteDC(hDC);

    return 0;
}