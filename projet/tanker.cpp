#include "tanker.h"

//----------------------------- Constructors -----------------------------------
Tanker::Tanker(const int &lane, const float &pos) : Character::Character(false, lane, pos)
{
    initModelPolygon();
    dead_ = false;
}

void Tanker::initModelPolygon()
{
    modelColor_ = {255, 0, 255, 255};

    modelPolygon_.push_back({0,4});
    modelPolygon_.push_back({0,1});
    modelPolygon_.push_back({-1,0});
    modelPolygon_.push_back({0,4});
    modelPolygon_.push_back({-4,0});
    modelPolygon_.push_back({-1,0});
    modelPolygon_.push_back({0,-1});
    modelPolygon_.push_back({-4,0});
    modelPolygon_.push_back({0,-4});
    modelPolygon_.push_back({0,-1});
    modelPolygon_.push_back({1,0});
    modelPolygon_.push_back({0,-4});
    modelPolygon_.push_back({4,0});
    modelPolygon_.push_back({1,0});
    modelPolygon_.push_back({0,1});
    modelPolygon_.push_back({4,0});
    modelPolygon_.push_back({0,4});
}

void Tanker::move(int movement, bool isCyclic, int polygonSize)
{
    // Tanker speed
    position_ = position_ - 0.0025;

    if(position_ < 0.0)
        kill();
}