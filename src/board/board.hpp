class Board
{
    private:
        std::string output;
    public:
        Board();

        void drawRect( HDC hdc );
        void drawFields( HDC hdc );
        int setSelected( HDC hdc, unsigned char selected );
        void drawCharacter( HDC hdc );
        void drawSymbols( HDC hdc );    //https://stackoverflow.com/questions/24169656/drawing-to-a-gdi-bitmap
        int setSymbol( HDC hdc, /*unsigned char figure,*/ unsigned char position );
};