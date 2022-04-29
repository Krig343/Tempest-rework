#ifndef SPIKER_H
#define SPIKER_H

#include "enemy.h" // class enemy

/* A specific class for the spiker since it has a particular ability
 */
class Spiker : public Enemy
{
public:
    // Constructors
    Spiker(const bool &shooting, const int &pos, const int &lane, const std::string &tpe);
    Spiker(Spiker &spik);

    // Spiker controls
    void createSpike(); // Creates a collidable objet & print it
};

#endif // SPIKER_H