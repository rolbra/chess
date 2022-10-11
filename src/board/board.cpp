#include <string>
#include <iostream>
#include <Windows.h>
#include "board.hpp"



Board::Board()
{
    std::cout << "init Chess Board" << std::endl;
    output = "\
        A       B       C       D       E       F       G       H\n\
\n\
    -----------------------------------------------------------------\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
8   |   T   |.  S  .|   L   |.  D  .|   K   |.  L  .|   S   |.  T  .|   8\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
7   |.  B  .|   B   |.  B  .|   B   |.  B  .|   B   |.  B  .|   B   |   7\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
6   |       |.......|       |.......|       |.......|       |.......|   6\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
5   |.......|       |.......|       |.......|       |.......|       |   5\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
4   |       |.......|       |.......|       |.......|       |.......|   4\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
3   |.......|       |.......|       |.......|       |.......|       |   3\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
2   |   B   |.. B ..|   B   |.. B ..|   B   |.. B ..|   B   |.. B ..|   2\n\
    |       |.......|       |.......|       |.......|       |.......|\n\
    |-------+-------+-------+-------+-------+-------+-------+-------|\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
1   |.. T ..|   S   |.. L ..|   D   |.. K ..|   L   |.. S ..|   T   |   1\n\
    |.......|       |.......|       |.......|       |.......|       |\n\
    -----------------------------------------------------------------\n\
    \n\
        A       B       C       D       E       F       G       H";
}

int Board::display()
{
    std::cout << output << std::endl << std::endl;
    return 0;
}

int Board::createStreightLine( COORD a, COORD b )
{
    int rc = 1;

    HWND cmd = GetConsoleWindow();
    HDC hDC = GetDC(cmd);

    if( a.Y == b.Y )
    {   //horizontal
        for( int x=a.X; x<b.X; x++)
            SetPixel(hDC, x, a.Y, RGB(0xFF,0x00,0x00));
        rc = 0;
    }
    else if( a.X == b.X )
    {
        //vertical
        for( int y=a.Y; y<b.Y; y++)
            SetPixel(hDC, a.X, y, RGB(0xFF,0x00,0x00));
        rc = 0;
    }
    else
    {
        //no streight line
        rc = -1;
    }
    
    ReleaseDC(cmd, hDC);
	DeleteDC(hDC);
    
    return rc;
}

int Board::createRect( COORD a, COORD b )
{
    return 0;
}

int Board::createRects()
{
    return 0;
}