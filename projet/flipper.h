#ifndef FLIPPER_H
#define FLIPPER_H

#include <SDL.h> // Graphical interface
#include "character.h"

class Flipper : public Character
{
public:
    int timeBeforeFlip_;

    // For flipping animation
    bool isFlipping_;
    int flippingFramesLeft_;

    bool dead_;

public:
    // Constructors
    Flipper(const int &lane, const float &pos);

    // Controls
    virtual void move(int movement, bool isCyclic, int polygonSize) override;
    inline void kill() { dead_ = true; };

    // Draw
    virtual void initModelPolygon() override;
};

#endif // FLIPPER_H