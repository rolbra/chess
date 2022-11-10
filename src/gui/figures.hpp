#pragma once

#include <Windows.h>
#include <gdiplus.h>
#include <string>

enum class FigureType
{
    rook,
    knight,
    bishop,
    queen,
    king,
    pawn
};

class Figure{
    public:
        FigureType type;
        Gdiplus::Bitmap *bitmap;
        unsigned char position;

        Figure();
        Figure( unsigned char position );
        ~Figure();
        FigureType getType();
        void setBitmap();
        //bmp filepath
        //Gdiplus::Bitmap rook( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\rook_black_48p.bmp", false );
        //todo: move vector
        //todo: move counter
};

class Rook : public Figure
{
    public: 
        Rook();
        Rook( unsigned char position );
};

class Knight : public Figure
{ 
    public: 
        Knight();
        Knight( unsigned char position );
};

class Bishop : public Figure{ 
    public: 
        Bishop();
        Bishop( unsigned char position );
};

class King : public Figure{ 
    public: 
        King();
        King( unsigned char position );
};

class Queen : public Figure{ 
    public: 
        Queen();
        Queen( unsigned char position );
};

class Pawn : public Figure{ 
    public: 
        Pawn();
        Pawn( unsigned char position );
};
