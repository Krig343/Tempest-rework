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
    Ennemi(const Ennemi &enmi);
    inline Ennemi &operator=(Ennemi &other)
    {
        if (this == &other)
            return *this;
    };
    inline Ennemi &operator=(Ennemi &&other)
    {
        if (this == &other)
            return *this;
    };

private:
    friend inline bool operator==(const Ennemi &lhs, const Ennemi &rhs)
    {
        if (lhs.type_ == rhs.type_ &&
            lhs.position_ == rhs.position_ &&
            lhs.lane_number_ == rhs.lane_number_)
            return true;
        return false;
    };
};

#endif // ENNEMI_H