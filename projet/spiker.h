#ifndef SPIKER_H
#define SPIKER_H

#include "ennemi.h" // class ennemi

/* A specific class for the spiker since it has a particular ability
 */
class Spiker : public Ennemi
{
public:
    // Constructors
    Spiker(const bool &shooting, const int &pos, const int &lane, const std::array<Uint8, 4> &color, const std::string &tpe);
    Spiker(Spiker &spik);

    // Spiker controls
    void createSpike(); // Creates a collidable objet & print it
};

#endif // SPIKER_H