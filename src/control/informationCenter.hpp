//manages Information about current Players, Games and Sessions
//load and save is made here

#pragma once

class InformationCenter
{
    unsigned char figurePositions[16];

public:
    InformationCenter();
    
    unsigned char getCurrentFigurePositions() const;
    void setNewFigurePositions( const unsigned char positions );
};