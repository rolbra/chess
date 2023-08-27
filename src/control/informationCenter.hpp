//manages Information about current Players, Games and Sessions
//load and save is made here

#pragma once

class InformationCenter
{
    unsigned char figurePositions[16];

    void checkScreenResolution();

public:
    unsigned int screenResolutionX, screenResolutionY;
    
    InformationCenter();
    
    unsigned char getCurrentFigurePositions() const;
    void setNewFigurePositions( const unsigned char positions );

    
};