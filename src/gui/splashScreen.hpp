#pragma once

#include <Windows.h>
#include <gdiplus.h>
#include <string>

class SplashScreen
{
private:
    HWND hwd;
    const WCHAR *filepath;

    POINT p;
    int deltaX, deltaY;
    int pictureWith, pictureHeight;
    void calculatePosition();

public:
    SplashScreen();
    SplashScreen( HWND hwd );
    ~SplashScreen();

    Gdiplus::Bitmap *picture;

    void setPicture( const WCHAR *filepath );
    int show();
};