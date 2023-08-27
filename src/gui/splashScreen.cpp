#include "splashScreen.hpp"
#include <fstream>

static std::ifstream file;
static std::ofstream chesslog;

SplashScreen::SplashScreen()
{
}

SplashScreen::SplashScreen( HWND hwd )
{
    this->hwd = hwd;
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::setPicture( const WCHAR *filepath )
{
    this->filepath = filepath;
    file.open( "..\\..\\PM\\bitmaps\\SplashScreens\\splash01.bmp" );
    if( !file )
    {
        chesslog.open( "chess.log", std::ios::app );
        chesslog << "..\\..\\PM\\bitmaps\\SplashScreens\\splash01.bmp";
    }
    else
    {
        picture = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\SplashScreens\\splash01.bmp", false );
    }
}

int SplashScreen::show()
{
    Gdiplus::Graphics graphicObject( this->hwd );

    graphicObject.DrawImage( this->picture, 100, 100 );
    
    return 0;
}