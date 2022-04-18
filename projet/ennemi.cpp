#include "ennemi.h"

int Ennemi::index_{0};

//----------------------------- Constructors -----------------------------------

Ennemi::Ennemi(const bool &shooting, const int &pos, const int &lane, const std::array<Uint8, 4> &color, const std::string &tpe) : Character::Character(shooting,
                                                                                                                                                        pos,
                                                                                                                                                        lane,
                                                                                                                                                        color),
                                                                                                                                   type_{tpe}
{
    ++index_;
}

Ennemi::Ennemi(const Ennemi &enmi) : Ennemi::Ennemi(enmi.is_shooting_,
                                                    enmi.position_,
                                                    enmi.lane_number_,
                                                    enmi.color_,
                                                    enmi.type_)
{
    ++index_;
}

Ennemi::~Ennemi()
{
    --index_;
}