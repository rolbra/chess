#include <iostream>
#include <Windows.h>
#include <gdiplus.h>
#include "board.hpp"

//start coordinate chessField
#define X 20
#define Y 20

//size single chessField
#define WIDTH 50
#define HEIGHT 50


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

void Board::drawFields( HDC hdc )
{
    Gdiplus::Graphics graphicObject( hdc );
    Gdiplus::Pen pen( Gdiplus::Color( 255, 255 , 0, 0 ), Gdiplus::REAL( 1.0F ) );
    Gdiplus::SolidBrush brush( Gdiplus::Color( 255, 0, 255, 0) );

    Gdiplus::Rect chessFields[64];
    int index = 0;
    for( int x = 0; x < 8; x++ )
    {
        for( int y = 0; y < 8; y++ )
        {
            chessFields[index++] = Gdiplus::Rect( X + WIDTH * x, Y + HEIGHT * y, WIDTH, HEIGHT );
        }
    }

    graphicObject.DrawRectangles( &pen, chessFields, 64 );
}