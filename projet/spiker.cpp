#include "spiker.h"

//----------------------------- Constructors -----------------------------------

Spiker::Spiker(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe) : Ennemi::Ennemi(shooting,
                                                                                                                                 pos,
                                                                                                                                 color,
                                                                                                                                 "spiker")
{
}

Spiker::Spiker(const Spiker &spik) : Spiker::Spiker(spik.is_shooting_,
                                                    spik.position_,
                                                    spik.color_,
                                                    "spiker")
{
}

//--------------------------- Spiker controls ----------------------------------

void Spiker::createSpike()
{
    // TODO
}