#include "player.h"

//----------------------------- Constructors -----------------------------------

Player::Player(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const int &life, const bool &zapper) : Character::Character(shooting,
                                                                                                                                                    pos,
                                                                                                                                                    color),
                                                                                                                               lives_{life},
                                                                                                                               used_zapper_{zapper}
{
}

//--------------------------- Player controls-----------------------------------

/* Checks if the zapper has been used and, if not, kills all the ennemies on the
 * electricwell. It does not destroy the spikes
 */
void Player::useZapper()
{
    used_zapper_ = true;
}