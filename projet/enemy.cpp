#include "enemy.h"

//----------------------------- Constructors -----------------------------------

Enemy::Enemy(const bool &shooting,
             const float &pos,
             const int &lane,
             const std::string &tpe) : Character::Character(shooting, lane, pos),
                                       type_{tpe}
{
}

Enemy::Enemy(Enemy &enmi) : Enemy::Enemy(enmi.is_shooting_,
                                         enmi.position_,
                                         enmi.lane_,
                                         enmi.type_)
{
}

Enemy::Enemy(const Enemy &enmi) : Enemy::Enemy(enmi.is_shooting_,
                                               enmi.position_,
                                               enmi.lane_,
                                               enmi.type_)
{
}

void Enemy::initModelPolygon()
{
}
