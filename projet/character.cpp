#include "character.h"

int Character::index_{0};

//----------------------------- Constructors -----------------------------------

Character::Character(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color) : is_shooting_{shooting},
                                                                                                position_{pos},
                                                                                                color_{color}
{
    ++index_;
}

Character::Character(const Character &car) : Character::Character(car.is_shooting_,
                                                                  car.position_,
                                                                  car.color_)
{
    ++index_;
}

Character::~Character()
{
    --index_;
}

//-------------------------- Caracter controls ---------------------------------

void Character::shoot(SDL_Renderer *renderer)
{
    is_shooting_ = true;
    // TODO : print the bullets and wait
    is_shooting_ = false;
}

/* Get the input key and move the lane by one according to the direction
 */
void Character::move(const int *pos)
{
    position_ = *pos;
}

//--------------------------------- IO -----------------------------------------

void Character::drawCaracter(SDL_Renderer *renderer)
{
    // TODO
}