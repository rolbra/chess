#include <Windows.h>
#include <iostream>
#include "board.hpp"
#include "referee.hpp"

Referee::Referee()
{
    board = new Board();
};

Referee::~Referee()
{
    delete board;
}

int Referee::move( HDC hdc, unsigned char to )
{
    board->setHdc( hdc );
    //is user's turn?
    
    //is symbol valid?

    //is move valid?

    //move!
    board->setSelected( to );

    board->unsetHdc();
    return 0;
}