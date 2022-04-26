#include "spiker.h"

//----------------------------- Constructors -----------------------------------

Spiker::Spiker(const bool &shooting,
               const int &pos,
               const int &lane,
               const std::array<Uint8, 4> &color,
               const std::string &tpe) : Ennemi::Ennemi(shooting,
                                                        pos,
                                                        lane,
                                                        color,
                                                        "spiker")
{
}

Spiker::Spiker(Spiker &spik) : Spiker::Spiker(spik.is_shooting_,
                                              spik.position_,
                                              spik.lane_number_,
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