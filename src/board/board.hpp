class Board
{
    private:
        std::string output;
        HDC currentHdc;
    public:
        Board();
        void setHdc( HDC hdc );
        void unsetHdc();
        
        void drawRect();
        void drawFields();
        void init( HDC hdc );
        int setSelected( unsigned char selected );
        void drawCharacter();
        void drawSymbols();    //https://stackoverflow.com/questions/24169656/drawing-to-a-gdi-bitmap
        int setSymbol( /*unsigned char figure,*/ unsigned char position );
};