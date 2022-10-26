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
        int setFigures( /*unsigned char figure,*/ unsigned char *positions, int arrayLength );
};