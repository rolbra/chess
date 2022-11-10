#pragma once

#include "board.hpp"

class Referee
{
    private:
        HDC currentHdc;
        unsigned char figurePositions[16];
        
    public:
        Board *board;
        
        Referee();
        ~Referee();
        
        int setup( HDC hdc );
        int move( HDC hdc, /*string symbol, unsigned char from */ unsigned char to );
};