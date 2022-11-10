#include "input.hpp"

int Input::checkInputWChar()
{
    int len = wcslen( input );
    if( len != 2 )
        return -1;

    if( isalpha( input[0] ) )
        return -2;

    if( isdigit( input[0] ) )
        return -3;
        
    return 0;
}

int Input::checkInputString()
{
    if( usrInput.length() != 2 )
        return -1;
    
    if( isalpha(usrInput[0]) != 0 )
        return -2;

    if( isdigit(usrInput[1]) != 0)
        return -3;

    return 0;
}