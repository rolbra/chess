class Board
{
    private:
        std::string output;
    public:
        Board();

        void drawRect( HDC hdc );
        void drawFields( HDC hdc );
        void drawCharacter( HDC hdc );
};