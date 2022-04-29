#ifndef FLIPPER_H
#define FLIPPER_H

#include <SDL.h> // Graphical interface
#include "character.h"

class Flipper : public Character
{
public:
    int time_before_flip_;
    bool dead_;

public:
    // Constructors
    Flipper(const float &pos, const int &lane);

    // Controls
    virtual void move(int movement, bool isCyclic, int polygonSize) override;
    inline void kill() { dead_ = true; };

    // Draw
    virtual void initModelPolygon() override;
};

#endif // FLIPPER_H