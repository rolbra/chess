
#include <string>
#include "informationCenter.hpp"
#include <wtypes.h>
#include <fstream>
#include <Windows.h>
#include <shellscalingapi.h>


static std::ifstream conf;
static std::ofstream chesslog;

ConfigManager::ConfigManager()
{}

std::string ConfigManager::getFromConfig( const std::string *flag )
{
    conf.open("../../chess.config");
    if( !conf )
    {
        chesslog.open( "chess.log", std::ios::app );
        chesslog << "no File chess.config found";
        chesslog.close();
        return "";
    }
    else
    {
        //find method here
        //return result
        return "";
    }
}


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

   //check Monitor Scaling
   HMONITOR hMonitor = MonitorFromWindow( hDesktop, MONITOR_DEFAULTTOPRIMARY );
   DEVICE_SCALE_FACTOR devScaleFactor;
   HRESULT res = GetScaleFactorForMonitor( hMonitor, &devScaleFactor );
   this->scale = devScaleFactor;
}

unsigned int InformationCenter::getX()
{
    checkScreenResolution();
    return screenResolutionX;
}

unsigned int InformationCenter::getY()
{
    checkScreenResolution();
    return screenResolutionY;
}

double InformationCenter::getScale()
{
    return this->scale / 100;
}