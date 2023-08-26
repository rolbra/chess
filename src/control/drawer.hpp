//responsable for all Paint Processes in the grafical User Interface

#pragma once

#include "board.hpp"

class Drawer
{
private:    
    HDC currentHdc;

public:
    Drawer();
    ~Drawer();

    Board *board;

    int setFigures( HDC hdc );
    int move( HDC hdc, /*string symbol, unsigned char from */ unsigned char to );
};