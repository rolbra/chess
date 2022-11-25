#include "input.hpp"

int Input::checkInputWChar()
{
    int len = wcslen( userInput );
    if( len != 5 )
    {
        error = L"error";
        return -1;
    }

    if( !isalpha( userInput[0] ) || !isalpha( userInput[3] ) )
        return -2;

    if( !isdigit( userInput[1] ) || !isdigit( userInput[4] ) )
        return -3;
        
    if( userInput[2] != ':' || userInput[2] != '-' )
        return -4;

    return 0;
}

MoveInfo Input::getMoveInfo()
{
    MoveInfo info;

    //splitt string
    
    return info;
}