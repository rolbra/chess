#include <iostream>
#include <Windows.h>
#include <gdiplus.h>
#include "board.hpp"
#include <array>

//start coordinate chessField
#define X 40
#define Y 40

//size single chessField
#define WIDTH 50
#define HEIGHT 50
#define bitmapSpan 1

#define FIGURESIZE L"48"

Board::Board()
{
    std::cout << "init Chess Board" << std::endl;
}

void Board::setHdc( HDC hdc )
{
    this->currentHdc = hdc;
}

void Board::unsetHdc()
{
    this->currentHdc = nullptr;
}

void Board::drawRect()
{
    Gdiplus::Graphics graficObject( this->currentHdc );
    Gdiplus::Pen pen( Gdiplus::Color( 255, 255 , 0, 0 ), Gdiplus::REAL( 1.0F ) );
    Gdiplus::SolidBrush brush( Gdiplus::Color( 255, 0, 255, 0) );
    
    graficObject.DrawRectangle( &pen, Gdiplus::Rect( 20, 20, 100, 100) );
}

void Board::drawFields()
{
    Gdiplus::Graphics graphicObject( this->currentHdc );
    Gdiplus::Pen pen( Gdiplus::Color( 255, 255 , 0, 0 ), Gdiplus::REAL( 1.0F ) );

    Gdiplus::Rect chessFields[64];
    
    //Gdiplus::Brush *sb( WHITE_BRUSH );
    Gdiplus::SolidBrush blackBrush(Gdiplus::Color(255, 0, 0, 0));

    int index = 0;
    for( int x = 0; x < 8; x++ )
    {
        for( int y = 0; y < 8; y++ )
        {
            chessFields[index] = Gdiplus::Rect( X + WIDTH * x, Y + HEIGHT * y, WIDTH, HEIGHT );
            if( ( x % 2 == 0 ) && ( y % 2 == 0) || ( x % 2 == 1 ) && ( y % 2 == 1 ) )
                graphicObject.FillRectangle( &blackBrush, chessFields[index] );
            index++;
        }
    }

    graphicObject.DrawRectangles( &pen, chessFields, 64 );
}

void Board::init( HDC hdc )
{
    this->currentHdc = hdc;
    drawFields();
    drawCharacter();
    this->currentHdc = nullptr;
}

int Board::setSelected( unsigned char selected )
{
    if( selected <= 0 )
        return -1;
    if( ( selected >> 4 ) > 0x07 )
        return -2;
    if( ( selected & 0x0F ) > 0x07 )
        return -3;

    drawFields();

    Gdiplus::Graphics graphicObject( this->currentHdc );
    Gdiplus::Pen pen( Gdiplus::Color::Navy, 3.0F );
    Gdiplus::Rect selectedRect( X + WIDTH * (selected >> 4), Y + HEIGHT * (selected & 0x0F), WIDTH, HEIGHT );
    graphicObject.DrawRectangle( &pen, selectedRect );
    return 0;
}

//todo: change positions to defines
void Board::drawCharacter()
{
    Gdiplus::Graphics graphicObject( this->currentHdc );
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

int Board::setFigures( unsigned char *positions, int arrayLength )
{
    //check array data
    /*if( position <= 0 )
        return -1;
    if( ( position >> 4 ) > 0x07 )
        return -2;
    if( ( position & 0x0F ) > 0x07 )
        return -3;
    */

    Gdiplus::Graphics graphicObject( this->currentHdc );

    Gdiplus::Bitmap rook( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\rook_black_48p.bmp", false );
    Gdiplus::Bitmap knight( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\knight_black_48p.bmp", false );
    Gdiplus::Bitmap bishop( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\bishop_black_48p.bmp", false );
    Gdiplus::Bitmap king( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\king_black_48p.bmp", false );
    Gdiplus::Bitmap queen( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\queen_black_48p.bmp", false );
    Gdiplus::Bitmap pawn( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\pawn_black_48p.bmp", false );

    std::array<Gdiplus::Bitmap*, 8> figures{ &rook, &knight, &bishop, &queen, &king, &bishop, &knight, &rook };
    
    int i = 0;
    //draw first row
    for( ; i < arrayLength / 2; i++ )
    {
        graphicObject.DrawImage( figures[i], X + WIDTH * ( positions[i] >> 4 ) + bitmapSpan, Y + HEIGHT * ( positions[i] & 0x0F ) + bitmapSpan );
    }
    //draw second row
    for( ; i < arrayLength; i++ )
    {
        graphicObject.DrawImage( &pawn, X + WIDTH * ( positions[i] >> 4 ) + bitmapSpan, Y + HEIGHT * ( positions[i] & 0x0F ) + bitmapSpan );
    }
    return 0;
}