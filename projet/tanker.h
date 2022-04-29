#ifndef TANKER_H
#define TANKER_H

#include <SDL.h> // Graphical interface
#include "character.h"

class Tanker : public Character
{
public:
    bool dead_;

public:
    // Constructors
    Tanker(const float &pos, const int &lane);

    // Controls
    virtual void move(int movement, bool isCyclic, int polygonSize) override;
    inline void kill() { dead_ = true; };

    // Draw
    virtual void initModelPolygon() override;
};

#endif // TANKER_H