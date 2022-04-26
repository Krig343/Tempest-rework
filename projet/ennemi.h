#ifndef ENNEMI_H
#define ENNEMI_H

#include "character.h" // class character

/* All ennemi characters. Son of the character class and parent of some ennemi
 * classes
 */
class Ennemi : public Character
{
public:
    const std::string type_; // The type of the ennemi

public:
    // Constructors
    Ennemi(const bool &shooting, const int &pos, const int &lane, const std::array<Uint8, 4> &color, const std::string &tpe);
    Ennemi(Ennemi &enmi);
};

#endif // ENNEMI_H