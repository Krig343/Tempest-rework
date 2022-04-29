#ifndef SPIKER_H
#define SPIKER_H

#include "character.h" // class enemy

/* A specific class for the spiker since it has a particular ability
 */
class Spiker : public Character
{
public:
    // Constructors
    Spiker(const int &pos, const int &lane);

    // Spiker controls
    void createSpike(); // Creates a collidable objet & print it

    // Draw
    virtual void initModelPolygon() override;
};

#endif // SPIKER_H