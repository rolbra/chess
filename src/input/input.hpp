#include <string>
#include <cctype>

class Input
{
private:
    std::string usrInput;
    std::string correctedInput;
public:
    wchar_t input[64];
    int checkInputWChar();
    int checkInputString();
};