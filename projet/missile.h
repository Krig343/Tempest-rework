#ifndef MISSILE_H
#define MISSILE_H

#include <SDL.h> // graphical interface

class Missile
{
private:
    int position_;

public:
    // Constructors
    Missile(const int &pos);

    // Missile controls
    void move();

    // IO
    void draw(SDL_Renderer *renderer);
};

#endif // MISSILE_H