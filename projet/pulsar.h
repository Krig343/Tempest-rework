#ifndef PULSAR_H
#define PULSAR_H

#include "ennemi.h" // class ennemi

/* A specific class for the pulsar since it has a particular ability
 */
class Pulsar : public Ennemi
{
private:
    bool is_pulsing_; // True if pulsing

public:
    // Constructors
    Pulsar(const bool &shooting, const int &pos, const int &lane, const std::string &tpe, bool pulse);
    Pulsar(Pulsar &puls);

    // Pulsar controls
    int pulse(int &lives, const int &lane); // Pulses on its current lane
};

#endif // PULSAR_H