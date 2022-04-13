#include "player.h"

// Constructors
Player::Player(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const int &life, const bool &zapper) : Character::Character(shooting,
                                                                                                                                                    pos,
                                                                                                                                                    color),
                                                                                                                               lives_{life},
                                                                                                                               used_zapper_{zapper}
{
}

// Player controls
void Player::loseLife()
{
    lives_--;
}

void Player::addLife()
{
    lives_++;
}

void Player::useZapper()
{
    used_zapper_ = true;
}

void Player::regenZapper()
{
    used_zapper_ = false;
}