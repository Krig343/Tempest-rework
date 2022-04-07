#ifndef ENNEMI_H
#define ENNEMI_H

#include "character.h"

class Ennemi : public Character
{
private:
    std::string type_; // Use rather an enum
    // Add bool is_pulsing_ with std::enable_if with the enum corresponding to pulsar

public:
    // Constructors
    Ennemi(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe);
    Ennemi(const Ennemi &enmi);
    ~Ennemi() = default;

    // Ennemi controls
    void getKilled(); // Maybe replaced with combination of collisionTest and removeCaracter

    // Add createSpike with an std::enable_if and the enum corresponding to spiker
    // Add pulse with and std::enable_if and the enum corresponding to pulsar
};

#endif // ENNEMI_H