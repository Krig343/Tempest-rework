#include "player.h"

//----------------------------- Constructors -----------------------------------
Player::Player(const bool &shooting,
               const float &pos,
               const int &lane,
               const int &life, 
               const bool &zapper) : Character::Character(shooting, lane, pos),
                                     lives_{life},
                                     used_zapper_{zapper}
{
    initModelPolygon();
}

void Player::initModelPolygon()
{
    modelColor_ = {255, 255, 0, 255};

    modelPolygon_.push_back({-5,0});
    modelPolygon_.push_back({-1,-2});
    modelPolygon_.push_back({-3,0});
    modelPolygon_.push_back({-1,1});
    modelPolygon_.push_back({3,0});
    modelPolygon_.push_back({1,-2});
    modelPolygon_.push_back({5,0});
    modelPolygon_.push_back({-1,3});
    modelPolygon_.push_back({-5,0});
}

void Player::move(int movement, float speed, bool isCyclic, int polygonSize)
{
    int newLane = lane_ + movement;

    // To avoid % of negative integers
    if((isCyclic)&&(newLane < 0)){
        lane_ = polygonSize - 1;
        return;
    }

    if(isCyclic)
    {
        lane_ = newLane%polygonSize;
    } else {
        if(movement < 0)
        {
            lane_ = std::max(0, newLane);
        } else {
            lane_ = std::min(newLane, polygonSize - 2);
        }
    }
}