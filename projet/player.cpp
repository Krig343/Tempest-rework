#include "player.h"

//----------------------------- Constructors -----------------------------------

Player::Player(const bool &shooting,
               const int &pos,
               const int &lane,
               const std::array<Uint8, 4> &color,
               const int &life, const bool &zapper,
               const std::array<Uint8, 4> &zapper_color) : Character::Character(shooting,
                                                                                pos,
                                                                                lane,
                                                                                color),
                                                           lives_{life},
                                                           used_zapper_{zapper},
                                                           zapper_color_{zapper_color}
{
}