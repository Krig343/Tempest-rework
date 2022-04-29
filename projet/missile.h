#ifndef MISSILE_H
#define MISSILE_H

#include <SDL.h> // graphical interface

class Missile
{
public:
    int position_;

public:
    // Constructors
    Missile(const int &pos);

    // Missile controls
    void move();

    // IO
    void draw(SDL_Renderer *renderer);

private:
    friend inline bool operator==(const Missile &lhs, const Missile &rhs)
    {
        if (lhs.position_ == rhs.position_)
            return true;
        return false;
    };
};

#endif // MISSILE_H