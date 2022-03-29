#include "ennemi.h"

//----------------------------- Constructors -----------------------------------

Ennemi::Ennemi(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe) : Character::Character(shooting,
                                                                                                                                       pos,
                                                                                                                                       color),
                                                                                                                  type_{tpe}
{
}

Ennemi::Ennemi(const Ennemi &enmi) : Ennemi::Ennemi(enmi.is_shooting_,
                                                    enmi.position_,
                                                    enmi.color_,
                                                    enmi.type_)
{
}

//--------------------------- Ennemi controls ----------------------------------

void Ennemi::getKilled()
{
    // TODO
}