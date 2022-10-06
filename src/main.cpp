#include <iostream>
#include "board/field.hpp"

int main()
{
    std::cout << "Hello Chess Player";

    Field chessBoard;

    chessBoard.display();

    return 0;
}