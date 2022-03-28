#ifndef ENNEMI_H
#define ENNEMI_H

#include "character.h"

class Ennemi : public Character
{
private:
    std::string type_; // Maybe more an enum than a string

public:
    // Constructors
    Ennemi(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe);
    Ennemi(const Ennemi &enmi);
    ~Ennemi() = default;

    // Ennemi controls
    void getKilled(); // Maybe replaced with combination of collisionTest and removeCaracter
};

#endif // ENNEMI_H