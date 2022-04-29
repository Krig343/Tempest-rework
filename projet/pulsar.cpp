#include "pulsar.h"

//----------------------------- Constructors -----------------------------------

Pulsar::Pulsar(const bool &shooting,
               const int &pos,
               const int &lane,
               const std::string &tpe,
               bool pulse) : Ennemi::Ennemi(shooting,
                                            pos,
                                            lane,
                                            "pulsar"),
                             is_pulsing_{pulse}
{
}

Pulsar::Pulsar(Pulsar &puls) : Pulsar::Pulsar(puls.is_shooting_,
                                              puls.position_,
                                              puls.lane_,
                                              "pulsar",
                                              puls.is_pulsing_)
{
}

//--------------------------- Spiker controls ----------------------------------

/* If the player is on the same lane as the pulsar, then he loses a life. Return
 * the number of lives left. You need to change the color of the lane when
 * calling this function.
 */

int Pulsar::pulse(int &lives, const int &lane)
{
    // Change lane color
    is_pulsing_ = true;
    if (lane == lane_)
        return --lives;
    return lives;
    is_pulsing_ = false;
}