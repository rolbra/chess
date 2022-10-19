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
};