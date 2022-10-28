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
    //A1 rook
    figurePositions[0] = 0x07;
    //B1 knight
    figurePositions[1] = 0x17;
    //C1 bishop
    figurePositions[2] = 0x27;
    //D1 queen
    figurePositions[3] = 0x37;
    //E1 king
    figurePositions[4] = 0x47;
    //F1 bishop
    figurePositions[5] = 0x57;
    //G1 knight
    figurePositions[6] = 0x67;
    //H1 rook
    figurePositions[7] = 0x77;
    
    //pawns
    //A2
    figurePositions[8] = 0x06;
    //B2
    figurePositions[9] = 0x16;
    //C2
    figurePositions[10] = 0x26;
    //D2
    figurePositions[11] = 0x36;
    //E2
    figurePositions[12] = 0x46;
    //F2
    figurePositions[13] = 0x56;
    //G2
    figurePositions[14] = 0x66;
    //H2
    figurePositions[15] = 0x76;
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
    
    //figurePositions[1] = to;
    //board->setFigures( figurePositions, sizeof( figurePositions ) );
    //board->setSelected( to );

    board->unsetHdc();
    return 0;
}