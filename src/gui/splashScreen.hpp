#pragma once

#include <Windows.h>
#include <gdiplus.h>
#include <string>

class SplashScreen
{
private:
    const WCHAR *filepath;

    POINT p;
    int deltaX, deltaY;
    int pictureWith, pictureHeight;
    void calculatePosition();

public:
    SplashScreen();
    ~SplashScreen();

    Gdiplus::Image *image;

    void setPicture( const WCHAR *filepath );
    int show( HDC hdc);
};