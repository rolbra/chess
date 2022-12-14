#include "board.hpp"

//start coordinate chessField
#define X 40
#define Y 40

//size single chessField
#define WIDTH 50
#define HEIGHT 50
#define BITMAP_SPAN 1

#define FIGURESIZE L"48"

Board::Board()
{
    std::cout << "init Chess Board" << std::endl;
}

Board::~Board()
{
    for( int i = 0; i < 16; i++ )
        delete figuresBlack[i];
}

void Board::initFigures()
{
    figuresBlack[0] = new Rook( 0x07 );
    figuresBlack[1] = new Knight( 0x17 );
    figuresBlack[2] = new Bishop( 0x27 );
    figuresBlack[3] = new Queen( 0x37 );
    figuresBlack[4] = new King( 0x47 );
    figuresBlack[5] = new Bishop( 0x57 );
    figuresBlack[6] = new Knight( 0x67 );
    figuresBlack[7] = new Rook( 0x77 );
    figuresBlack[8] = new Pawn( 0x06 );
    figuresBlack[9] = new Pawn( 0x16 );
    figuresBlack[10] = new Pawn( 0x26 );
    figuresBlack[11] = new Pawn( 0x36 );
    figuresBlack[12] = new Pawn( 0x46 );
    figuresBlack[13] = new Pawn( 0x56 );
    figuresBlack[14] = new Pawn( 0x66 );
    figuresBlack[15] = new Pawn( 0x76 );
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
    
    Gdiplus::SolidBrush blackBrush(Gdiplus::Color(75, 0, 0, 0));

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

void Board::drawBoard( HDC hdc )
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

int Board::drawFigure( Figure *figure )
{
    //maybe for other colors: //https://learn.microsoft.com/de-de/windows/win32/gdiplus/-gdiplus-using-a-color-remap-table-use?redirectedfrom=MSDN

    Gdiplus::Graphics graphicObject( this->currentHdc );
    
    if( figure == nullptr )
        return -1;

    graphicObject.DrawImage( figure->bitmap, X + WIDTH * ( figure->position >> 4 ) + BITMAP_SPAN, Y + HEIGHT * ( figure->position & 0x0F ) + BITMAP_SPAN );

    return 0;
}

int Board::drawFigures()
{   
    Gdiplus::Graphics graphicObject( this->currentHdc );
    
    int i = 0;
    int size = figuresBlack.size();
    //draw first row
    for( ; i < size / 2; i++ )
    {
        graphicObject.DrawImage( figuresBlack[i]->bitmap, X + WIDTH * ( figuresBlack[i]->position >> 4 ) + BITMAP_SPAN, Y + HEIGHT * ( figuresBlack[i]->position & 0x0F ) + BITMAP_SPAN );
    }
    //draw second row
    for( ; i < size; i++ )
    {
        graphicObject.DrawImage( figuresBlack[i]->bitmap, X + WIDTH * ( figuresBlack[i]->position >> 4 ) + BITMAP_SPAN, Y + HEIGHT * ( figuresBlack[i]->position & 0x0F ) + BITMAP_SPAN );
    }

    return 0;
}