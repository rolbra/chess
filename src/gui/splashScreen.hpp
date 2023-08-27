#pragma once^

#include <Windows.h>
#include <gdiplus.h>
#include <string>

class SplashScreen
{
private:
    HWND hwd;
    const WCHAR *filepath;

public:
    SplashScreen();
    SplashScreen( HWND hwd );
    ~SplashScreen();

    Gdiplus::Bitmap *picture;

    void setPicture( const WCHAR *filepath );
    int show();
};