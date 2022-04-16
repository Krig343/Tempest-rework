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

/* Creates an object of class Spike and calls its print method on the furterst
 * spot it came on the lane
 */
void Spiker::createSpike()
{
    // TODO
}