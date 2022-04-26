#include "ennemi.h"

//----------------------------- Constructors -----------------------------------

Ennemi::Ennemi(const bool &shooting,
               const int &pos,
               const int &lane,
               const std::array<Uint8, 4> &color,
               const std::string &tpe) : Character::Character(shooting,
                                                              pos,
                                                              lane,
                                                              color),
                                         type_{tpe}
{
}

Ennemi::Ennemi(Ennemi &enmi) : Ennemi::Ennemi(enmi.is_shooting_,
                                              enmi.position_,
                                              enmi.lane_number_,
                                              enmi.color_,
                                              enmi.type_)
{
}

Ennemi::Ennemi(const Ennemi &enmi) : Ennemi::Ennemi(enmi.is_shooting_,
                                                    enmi.position_,
                                                    enmi.lane_number_,
                                                    enmi.color_,
                                                    enmi.type_)
{
}