#include "player.h"

//----------------------------- Constructors -----------------------------------

Player::Player(const bool &shooting,
               const float &pos,
               const int &lane,
               const int &life,
               const bool &zapper) : Character::Character(shooting,
                                                          pos,
                                                          lane),
                                     lives_{life},
                                     used_zapper_{zapper}
{
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