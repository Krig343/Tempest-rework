#ifndef ENEMY_H
#define ENEMY_H

#include "character.h" // class character

/* All enemy characters. Son of the character class and parent of some enemy
 * classes
 */
class Enemy : public Character
{
public:
    const std::string type_; // The type of the enemy

public:
    // Constructors
    Enemy(const bool &shooting,
          const float &pos,
          const int &lane,
          const std::string &tpe);
    Enemy(Enemy &enmi);
    Enemy(const Enemy &enmi);
    inline Enemy &operator=(Enemy &other)
    {
        if (this == &other)
            return *this;
    };
    inline Enemy &operator=(Enemy &&other)
    {
        if (this == &other)
            return *this;
    };

protected:
    virtual void initModelPolygon() override;

private:
    friend inline bool operator==(const Enemy &lhs, const Enemy &rhs)
    {
        if (lhs.type_ == rhs.type_ &&
            lhs.position_ == rhs.position_ &&
            lhs.lane_ == rhs.lane_)
            return true;
        return false;
    };
};

#endif // ENEMY_H