#include "pulsar.h"

//----------------------------- Constructors -----------------------------------

Pulsar::Pulsar(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe, bool pulse) : Ennemi::Ennemi(shooting,
                                                                                                                                             pos,
                                                                                                                                             color,
                                                                                                                                             "pulsar"),
                                                                                                                              is_pulsing_{pulse}
{
}

Pulsar::Pulsar(const Pulsar &puls) : Pulsar::Pulsar(puls.is_shooting_,
                                                    puls.position_,
                                                    puls.color_,
                                                    "pulsar",
                                                    puls.is_pulsing_)
{
}

//--------------------------- Spiker controls ----------------------------------

/* If the player is on the same lane as the pulsar, then he loses a life
 */

void Pulsar::pulse()
{
    is_pulsing_ = true;
    // TODO : change se lane color and test if the player is on the lane (and eventualy lose life)
    is_pulsing_ = false;
}