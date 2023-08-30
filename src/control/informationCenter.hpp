//manages Information about current Players, Games and Sessions
//load and save is made here

#pragma once

class ConfigManager
{
public:
    ConfigManager();
    std::string getFromConfig( const std::string *flag );
};

class InformationCenter
{
    unsigned char figurePositions[16];

    void checkScreenResolution();
    unsigned int screenResolutionX, screenResolutionY;

public:
    
    int getX();
    int getY();
    InformationCenter();
    
    unsigned char getCurrentFigurePositions() const;
    void setNewFigurePositions( const unsigned char positions );

    
};