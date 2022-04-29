#include "ennemi.h"

//----------------------------- Constructors -----------------------------------

Ennemi::Ennemi(const bool &shooting,
               const float &pos,
               const int &lane,
               const std::string &tpe) : Character::Character(shooting, lane, pos),
                                         type_{tpe}
{
}

Ennemi::Ennemi(Ennemi &enmi) : Ennemi::Ennemi(enmi.isShooting_,
                                              enmi.position_,
                                              enmi.lane_,
                                              enmi.type_)
{
}

Ennemi::Ennemi(const Ennemi &enmi) : Ennemi::Ennemi(enmi.isShooting_,
                                                    enmi.position_,
                                                    enmi.lane_,
                                                    enmi.type_)
{
}

void Ennemi::initModelPolygon()
{
    
}

