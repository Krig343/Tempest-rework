#include "pulsar.h"

//----------------------------- Constructors -----------------------------------

Pulsar::Pulsar(const float &pos, const int &lane) : Character::Character(false, pos, lane)
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

void Pulsar::initModelPolygon()
{
}