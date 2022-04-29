#ifndef SPIKE_H
#define SPIKE_H

#include <SDL.h> // Graphical interface
#include "ennemi.h"

class Spike : public Ennemi
{
private:
    int position_;

public:
    // Constructors
    Spike(const int &lane, const float &pos);

    // Draw
    virtual void initModelPolygon() override;
};

#endif // SPIKE_H