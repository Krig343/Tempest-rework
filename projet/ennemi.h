#ifndef ENNEMI_H
#define ENNEMI_H

#include "character.h" // class character

/* All ennemi characters. Son of the character class and parent of some ennemi
 * classes
 */
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