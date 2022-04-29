#ifndef PULSAR_H
#define PULSAR_H

#include "character.h"

/* A specific class for the pulsar since it has a particular ability
 */
class Pulsar : public Character
{
private:
    bool is_pulsing_; // True if pulsing

public:
    // Constructors
    Pulsar(const float &pos, const int &lane);

    // Pulsar controls
    int pulse(int &lives, const int &lane); // Pulses on its current lane

    // Draw
    virtual void initModelPolygon() override;
};

#endif // PULSAR_H