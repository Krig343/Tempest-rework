#include "character.h"

//----------------------------- Constructors -----------------------------------

Character::Character(const bool &shooting,
                     const int &pos,
                     const int &lane,
                     const std::array<Uint8, 4> &color) : is_shooting_{shooting},
                                                          position_{pos},
                                                          lane_number_{lane},
                                                          color_{color}
{
}

Character::Character(Character &car) : Character::Character(car.is_shooting_,
                                                                  car.position_,
                                                                  car.lane_number_,
                                                                  car.color_)
{
}

//-------------------------- Caracter controls ---------------------------------

void Character::shoot(SDL_Renderer *renderer)
{
    is_shooting_ = true;
    // TODO : print the bullets and wait
    is_shooting_ = false;
}

/* Needs redesign
 */
void Character::move(const int &pos)
{
    if (pos < 0)
        position_ -= 1 % 16;
    else if (pos > 0)
        position_ += 1 % 16;
}

//--------------------------------- IO -----------------------------------------

void Character::drawCaracter(SDL_Renderer *renderer)
{
    // TODO
}