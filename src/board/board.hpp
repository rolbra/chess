class Board
{
    private:
        std::string output;
        HDC currentHdc;
    public:
        Board();
        void setHdc( HDC hdc );
        void unsetHdc();
        
        //draw single field
        void drawRect();

        //draw all chess fields
        void drawFields();

        //draw 1-8 and A to H
        void drawCharacter();

        //draw chess fields and characters
        void init( HDC hdc );

        //frame a specific field
        int setSelected( unsigned char selected );
        
        //positions for every figure stored in a char array
        //[black[rook0][knight0][bishop0][king][queen][bishop1]...][white[rook0]...]
        int setFigures( unsigned char *positions, int arrayLength );
};