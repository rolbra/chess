#include <Windows.h>
#include <gdiplus.h>

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

        FigureType getType();
        void setBitmap();
        //bmp filepath
        //Gdiplus::Bitmap rook( L"C:\\Users\\BRA\\source\\repos\\chess\\PM\\bitmaps\\rook_black_48p.bmp", false );
        //todo: move vector
        //todo: move counter
};

class Rook : public Figure{ public: Rook(); };
class Knight : public Figure{ public: Knight(); };
class Bishop : public Figure{ public: Bishop(); };
class King : public Figure{ public: King(); };
class Queen : public Figure{ public: Queen(); };
class Pawn : public Figure{ public: Pawn(); };