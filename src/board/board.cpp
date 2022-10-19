#include <iostream>
#include <Windows.h>
#include <gdiplus.h>
#include "board.hpp"

//start coordinate chessField
#define X 40
#define Y 40

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

//todo: change positions to defines
void Board::drawCharacter( HDC hdc )
{
    Gdiplus::Graphics graphicObject( hdc );
    Gdiplus::Pen pen( Gdiplus::Color( 255, 255 , 0, 0 ), Gdiplus::REAL( 1.0F ) );
    Gdiplus::SolidBrush solidBrush( Gdiplus::Color( 255, 0, 0, 255 ) );

    Gdiplus::FontFamily fontFamily( L"Arial" );
    Gdiplus::Font font( &fontFamily, 12, Gdiplus::FontStyle::FontStyleBold, Gdiplus::UnitPoint );
    Gdiplus::StringFormat stringFormat;

    // Center-justify each line of text.
    stringFormat.SetAlignment( Gdiplus::StringAlignmentCenter );

    // Center the block of text (top to bottom) in the rectangle.
    stringFormat.SetLineAlignment( Gdiplus::StringAlignmentCenter );
    
    WCHAR *stringsChar[8];
    stringsChar[0] = L"A";
    stringsChar[1] = L"B";
    stringsChar[2] = L"C";
    stringsChar[3] = L"D";
    stringsChar[4] = L"E";
    stringsChar[5] = L"F";
    stringsChar[6] = L"G";
    stringsChar[7] = L"H";

    WCHAR *stringsNum[8];
    stringsNum[0] = L"8";
    stringsNum[1] = L"7";
    stringsNum[2] = L"6";
    stringsNum[3] = L"5";
    stringsNum[4] = L"4";
    stringsNum[5] = L"3";
    stringsNum[6] = L"2";
    stringsNum[7] = L"1";
    
    Gdiplus::RectF positionsChar[16];
    for( int i = 0; i < 8; i++ )
    {
        positionsChar[i] = Gdiplus::RectF( 55.0f + WIDTH * i, 15.0f, 20.0f, 20.0f );
    }

    Gdiplus::RectF positionsNum[16];
    for( int i = 0; i < 8; i++ )
    {
        positionsNum[i] = Gdiplus::RectF( 15.0f, 55.0f + HEIGHT * i, 20.0f, 20.0f );
    }
    
    for( int i = 0; i < 8; i++)
    {
        graphicObject.DrawString( stringsChar[i], -1, &font, positionsChar[i], &stringFormat, &solidBrush );
    }
    
    for( int i = 0; i < 8; i++)
    {
        graphicObject.DrawString( stringsNum[i], -1, &font, positionsNum[i], &stringFormat, &solidBrush );
    }
}