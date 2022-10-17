#include <string>
#include <iostream>
#include <Windows.h>
#include <gdiplus.h>
#include "board.hpp"



Board::Board()
{
    std::cout << "init Chess Board" << std::endl;
}

void Board::drawRect( HDC hdc )
{
    Gdiplus::Graphics graficObject( hdc );
    Gdiplus::Pen pen( Gdiplus::Color( 255, 255 , 0, 0 ), Gdiplus::REAL( 1.0F ) );
    Gdiplus::SolidBrush brush( Gdiplus::Color( 255, 0, 255, 0) );
    
    graficObject.DrawRectangle( &pen, Gdiplus::Rect( 20, 20, 100, 100) );

}
