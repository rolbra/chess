class Board
{
    private:
        std::string output;
    public:
        Board();
        int createStreightLine( COORD a, COORD b );
        int createRect( COORD a, COORD b );
        int createRects();
        int display();
};