#include "flipper.h"

//----------------------------- Constructors -----------------------------------
Flipper::Flipper(const float &pos, const int &lane) : Character::Character(false, pos, lane)
{
    initModelPolygon();
    time_before_flip_ = 50;
    dead_ = false;
}

void Flipper::initModelPolygon()
{
    model_color_ = {255, 0, 0, 255};

    model_polygon_.push_back({-5, 2});
    model_polygon_.push_back({-3, 0});
    model_polygon_.push_back({-4, -1});
    model_polygon_.push_back({5, 2});
    model_polygon_.push_back({3, 0});
    model_polygon_.push_back({4, -1});
    model_polygon_.push_back({-5, 2});
}

void Flipper::move(int movement, float speed, bool isCyclic, int polygonSize)
{
    // Lane flip every 50 clock ticks
    if (time_before_flip_ == 0)
    {
        int newLane = lane_ + movement;

        if (isCyclic)
        {
            lane_ = newLane % polygonSize;
        }
        else
        {
            lane_ = std::min(newLane, polygonSize - 2);
        }

        time_before_flip_ = 50;
    }
    else
    {
        time_before_flip_--;
    }

    // Flipper speed
    position_ = std::max(0.0, position_ - 0.001*speed);
}
