#include "splashScreen.hpp"
#include <fstream>
#include "informationCenter.hpp"

#define screenTime 3000

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
    file.open( "..\\..\\PM\\bitmaps\\SplashScreens\\splash02.bmp" );
    if( !file )
    {
        chesslog.open( "chess.log", std::ios::app );
        chesslog << "..\\..\\PM\\bitmaps\\SplashScreens\\splash02.bmp";
    }
    else
    {
        picture = new Gdiplus::Bitmap( L"..\\..\\PM\\bitmaps\\SplashScreens\\splash02.bmp", false );
    }
}

void SplashScreen::calculatePosition()
{
    InformationCenter info;

    this->deltaX = info.getX() / 6;
    this->deltaY = info.getY() / 6;
    
    this->p.x = deltaX;
    this->p.y = deltaY;

    this->pictureWith = deltaX * 4;
    this->pictureHeight = deltaY * 4;
}

int SplashScreen::show()
{
    Gdiplus::Graphics graphicObject( this->hwd );
    
    calculatePosition();
    //graphicObject.DrawImage( this->picture, p.x, p.y, pictureWith, pictureHeight );
    graphicObject.DrawImage( this->picture, 640, 400, 2560, 1600 );

    Sleep( screenTime );

    return 0;
}