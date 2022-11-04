#include <Windows.h>
#include <gdiplus.h>
#include <string>
#include "figures.hpp"



FigureType Figure::getType()
{
    return type;
}

Rook::Rook()
{
    bitmap = new Gdiplus::Bitmap( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\rook_black_48p.bmp", false );
};

Knight::Knight()
{
    bitmap = new Gdiplus::Bitmap( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\knight_black_48p.bmp", false );
}

Bishop::Bishop()
{
    bitmap = new Gdiplus::Bitmap( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\bishop_black_48p.bmp", false );
}

King::King()
{
    bitmap = new Gdiplus::Bitmap( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\king_black_48p.bmp", false );
}

Queen::Queen()
{
    bitmap = new Gdiplus::Bitmap( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\queen_black_48p.bmp", false );
}

Pawn::Pawn()
{
    bitmap = new Gdiplus::Bitmap( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\pawn_black_48p.bmp", false );
}