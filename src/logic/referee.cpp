
#include "referee.hpp"

Referee::Referee()
{
    board = new Board();
};

Referee::~Referee()
{
    delete board;
}

int Referee::setFigures( HDC hdc )
{
    board->setHdc( hdc );

    //place all figures
    board->drawFigures();

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