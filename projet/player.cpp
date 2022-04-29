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