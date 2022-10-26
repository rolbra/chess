class Referee
{
    private:
        HDC currentHdc;
        Board *board;
    public:
        Referee();
        ~Referee();
        int move( HDC hdc, /*string symbol, unsigned char from */ unsigned char to );
};