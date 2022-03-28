#ifndef PULSAR_H
#define PULSAR_H

#include "ennemi.h"

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
    void pulse(); // Create a collidable objet & print it
};

#endif // PULSAR_H