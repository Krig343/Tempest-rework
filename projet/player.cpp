#include "player.h"

//----------------------------- Constructors -----------------------------------
Player::Player(const bool &shooting,
               const float &pos,
               const int &lane,
               const int &life) : Character::Character(shooting,
                                                       pos,
                                                       lane),
                                  lives_{life}
{
    zapper_left = 2;
    initModelPolygon();
}

void Player::initModelPolygon()
{
    model_color_ = {255, 255, 0, 255};
    zapper_color_ = {255, 255, 0, 255};

    model_polygon_.push_back({-5, 0});
    model_polygon_.push_back({-1, -2});
    model_polygon_.push_back({-3, 0});
    model_polygon_.push_back({-1, 1});
    model_polygon_.push_back({3, 0});
    model_polygon_.push_back({1, -2});
    model_polygon_.push_back({5, 0});
    model_polygon_.push_back({-1, 3});
    model_polygon_.push_back({-5, 0});
}

void Player::move(int movement, bool isCyclic, int polygonSize)
{
    int newLane = lane_ + movement;

    // To avoid % of negative integers
    if ((isCyclic) && (newLane < 0))
    {
        lane_ = polygonSize - 1;
        return;
    }

    if (isCyclic)
    {
        lane_ = newLane % polygonSize;
    }
    else
    {
        if (movement < 0)
        {
            lane_ = std::max(0, newLane);
        }
        else
        {
            lane_ = std::min(newLane, polygonSize - 2);
        }
    }
}