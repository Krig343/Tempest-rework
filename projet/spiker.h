// Will be removed

#ifndef SPIKER_H
#define SPIKER_H

#include "ennemi.h" // class ennemi

/* A specific class for the spiker since it has a particular ability
 */
class Spiker : public Ennemi
{
public:
    // Constructors
    Spiker(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe);
    Spiker(const Spiker &spik);
    ~Spiker() = default;

    // Spiker controls
    void createSpike(); // Create a collidable objet & print it
};

#endif // SPIKER_H