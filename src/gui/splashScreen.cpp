#include "splashScreen.hpp"
#include <fstream>
#include "informationCenter.hpp"

#define screenTime 3000

static std::ifstream file;
static std::ofstream chesslog;

SplashScreen::SplashScreen()
{
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
        image = new Gdiplus::Image( L"..\\..\\PM\\bitmaps\\SplashScreens\\splash02.JPG", false );
    }
}

void SplashScreen::calculatePosition()
{
    InformationCenter info;
    
    double scale = info.getScale();

    auto imageW = image->GetWidth();
    auto imageH = image->GetHeight();

    // this->deltaX = info.getX() * scale / 2 - image->GetWidth() / 2;
    // this->deltaY = info.getY() * scale / 2 - image->GetHeight() / 2;
    
    deltaX = info.getX();
    deltaY = info.getY();

    this->p.x = deltaX;
    this->p.y = deltaY;

    this->pictureWith = deltaX * 4 * scale;
    this->pictureHeight = deltaY * 4 * scale;
}

int SplashScreen::show( HDC hdc )
{
    Gdiplus::Graphics graphicObject( hdc );
    
    calculatePosition();
    //graphicObject.DrawImage( this->picture, p.x, p.y, pictureWith, pictureHeight );
    //graphicObject.DrawImage( this->picture, 640, 400, 2560, 1600 );
    graphicObject.DrawImage( image, 0, 0, 1024, 860 );

    Sleep( screenTime );

    return 0;
}