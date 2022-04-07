// Will be removed

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
    Pulsar(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe, bool pulse);
    Pulsar(const Pulsar &puls);
    ~Pulsar() = default;

    // Pulsar controls
    void pulse(); // Pulse on its current lane
};

#endif // PULSAR_H