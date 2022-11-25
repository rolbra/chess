#include <string>
#include <cctype>

struct MoveInfo
{
    unsigned char fromX;
    unsigned char fromY;
    unsigned char toX;
    unsigned char toY;
};

//wchar_t bla = L'bla';

class Input
{
private:
    std::string correctedInput;
public:
    wchar_t userInput[64];
    wchar_t error[64];
    int checkInputWChar();
    MoveInfo getMoveInfo();
};