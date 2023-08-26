#include "drawer.hpp"


Drawer::Drawer()
{
    board = new Board();
}

Drawer::~Drawer()
{
    delete board;
}

int Drawer::setFigures( HDC hdc )
{
    board->setHdc( hdc );

    //place all figures
    board->drawFigures();

    board->unsetHdc();
    return 0;
}

int Drawer::move( HDC hdc, unsigned char to )
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