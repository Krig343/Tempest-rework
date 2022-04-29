#include "flipper.h"

//----------------------------- Constructors -----------------------------------
Flipper::Flipper(const int &lane, const float &pos) : Character::Character(false, lane, pos)
{
    initModelPolygon();
    timeBeforeFlip_ = 50;
    dead_ = false;
}

void Flipper::initModelPolygon()
{
    modelColor_ = {255, 0, 0, 255};

    modelPolygon_.push_back({-5,2});
    modelPolygon_.push_back({-3,0});
    modelPolygon_.push_back({-4,-1});
    modelPolygon_.push_back({5,2});
    modelPolygon_.push_back({3,0});
    modelPolygon_.push_back({4,-1});
    modelPolygon_.push_back({-5,2});
}

void Flipper::move(int movement, bool isCyclic, int polygonSize)
{
    // Lane flip every 50 clock ticks
    if(timeBeforeFlip_ == 0){
        int newLane = lane_ + movement;

        if(isCyclic)
        {
            lane_ = newLane%polygonSize;
        } else {
            lane_ = std::min(newLane, polygonSize - 2);
        }
        
        timeBeforeFlip_ = 50;
    } else {
        timeBeforeFlip_--;
    }

    // Flipper speed
    position_ = std::max(0.0, position_ - 0.001);
}
