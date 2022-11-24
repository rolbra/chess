#include "figures.hpp"
#include <fstream>

std::ifstream file;
std::ofstream chesslog;

Figure::Figure()
{

}

Figure::Figure( unsigned char position )
{
    this->position = position;
}

Figure::~Figure()
{
    
}

FigureType Figure::getType()
{
    return type;
}

Rook::Rook()
{
    file.open( "..\\..\\PM\\bitmaps\\rook_black_48p.bmp" );
    if( !file )
    {
        chesslog.open( "chess.log", std::ios::app );
        chesslog << "..\\..\\PM\\bitmaps\\rook_black_48p.bmp not found";
    }
    else
    {
        bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\rook_black_48p.bmp", false );
    }
}

Rook::Rook( unsigned char position ) : Figure( position )
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\rook_black_48p.bmp", false );
    type = FigureType::rook;
}

Knight::Knight()
{   
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\knight_black_48p.bmp", false );
}

Knight::Knight( unsigned char position ) : Figure( position )
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\knight_black_48p.bmp", false );
}

Bishop::Bishop()
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\bishop_black_48p.bmp", false );
}

Bishop::Bishop( unsigned char position ) : Figure( position )
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\bishop_black_48p.bmp", false );
}

King::King()
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\king_black_48p.bmp", false );
}

King::King( unsigned char position ) : Figure( position )
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\king_black_48p.bmp", false );
}

Queen::Queen()
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\queen_black_48p.bmp", false );
}

Queen::Queen( unsigned char position ) : Figure( position )
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\queen_black_48p.bmp", false );
    type = FigureType::queen;
}

Pawn::Pawn()
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\pawn_black_48p.bmp", false );
}

Pawn::Pawn( unsigned char position ) : Figure( position )
{
    bitmap = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\pawn_black_48p.bmp", false );
}
