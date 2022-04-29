#include "tanker.h"

//----------------------------- Constructors -----------------------------------
Tanker::Tanker(const float &pos, const int &lane) : Character::Character(false, pos, lane)
{
    initModelPolygon();
    dead_ = false;
}

void Tanker::initModelPolygon()
{
    model_color_ = {255, 0, 255, 255};

    model_polygon_.push_back({0, 4});
    model_polygon_.push_back({0, 1});
    model_polygon_.push_back({-1, 0});
    model_polygon_.push_back({0, 4});
    model_polygon_.push_back({-4, 0});
    model_polygon_.push_back({-1, 0});
    model_polygon_.push_back({0, -1});
    model_polygon_.push_back({-4, 0});
    model_polygon_.push_back({0, -4});
    model_polygon_.push_back({0, -1});
    model_polygon_.push_back({1, 0});
    model_polygon_.push_back({0, -4});
    model_polygon_.push_back({4, 0});
    model_polygon_.push_back({1, 0});
    model_polygon_.push_back({0, 1});
    model_polygon_.push_back({4, 0});
    model_polygon_.push_back({0, 4});
}

void Tanker::move(int movement, bool isCyclic, int polygonSize)
{
    // Tanker speed
    position_ = position_ - 0.0025;

    if (position_ < 0.0)
        kill();
}