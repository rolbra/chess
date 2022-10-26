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

void Referee::initFigurePositions()
{
    figurePositions[0] = 0x07;
    figurePositions[1] = 0x77;
}

int Referee::setup( HDC hdc )
{
    board->setHdc( hdc );

    //place all figures
    initFigurePositions();
    board->setFigures( figurePositions, sizeof( figurePositions ) );

    board->unsetHdc();
    return 0;
}

int Referee::move( HDC hdc, unsigned char to )
{
    board->setHdc( hdc );
    //is user's turn?
    
    //is symbol valid?

    //is move valid?

    //move!
    figurePositions[1] = to;
    board->setFigures( figurePositions, sizeof( figurePositions ) );
    board->setSelected( to );

    board->unsetHdc();
    return 0;
}