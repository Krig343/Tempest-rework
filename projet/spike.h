#ifndef SPIKE_H
#define SPIKE_H

#include <SDL.h> // Graphical interface

class Spike
{
private:
    int position_;

public:
    // Constructors
    Spike(const int &pos);

    // IO
    void draw(SDL_Renderer *renderer);
};

#endif // SPIKE_H