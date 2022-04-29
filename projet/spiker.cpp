#include "spiker.h"

//----------------------------- Constructors -----------------------------------

Spiker::Spiker(const bool &shooting,
               const int &pos,
               const int &lane,
               const std::string &tpe) : Ennemi::Ennemi(shooting,
                                                        pos,
                                                        lane,
                                                        "spiker")
{
}

Spiker::Spiker(Spiker &spik) : Spiker::Spiker(spik.isShooting_,
                                              spik.position_,
                                              spik.lane_,
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