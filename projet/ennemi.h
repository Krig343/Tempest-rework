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
    Ennemi(const bool &shooting, const float &pos, const int &lane, const std::string &tpe);
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

protected:
    virtual void initModelPolygon() override;

private:
    friend inline bool operator==(const Ennemi &lhs, const Ennemi &rhs)
    {
        if (lhs.type_ == rhs.type_ &&
            lhs.position_ == rhs.position_ &&
            lhs.lane_ == rhs.lane_)
            return true;
        return false;
    };
};

#endif // ENNEMI_H