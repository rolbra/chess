class Referee
{
    private:
        HDC currentHdc;
        Board *board;
        void initFigurePositions();
        unsigned char figurePositions[16];
    public:
        Referee();
        ~Referee();
        int setup( HDC hdc );
        int move( HDC hdc, /*string symbol, unsigned char from */ unsigned char to );
};