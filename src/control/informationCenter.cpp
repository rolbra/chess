#pragma once

#include "informationCenter.hpp"
#include <wtypes.h>

InformationCenter::InformationCenter()
{
    checkScreenResolution();
}

void InformationCenter::checkScreenResolution()
{
    RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   this->screenResolutionX = desktop.right;
   this->screenResolutionY = desktop.bottom;
}

int InformationCenter::getX()
{
    checkScreenResolution();
    return screenResolutionX;
}

int InformationCenter::getY()
{
    checkScreenResolution();
    return screenResolutionY;
}