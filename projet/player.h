#ifndef PLAYER_H
#define PLAYER_H

#include "character.h" // class character

class Player : public Character
{
public:
    int lives_;        // Player's lives number
    bool used_zapper_; // True if player used his zapper

public:
    // Constructors
    Player(const bool &shooting, const float &pos, const int &lane, const int &life, const bool &zapper);

    // Player controls
    virtual void move(int movement, bool isCyclic, int polygonSize) override;
    inline void loseLife() { --lives_; };                // Decrease lives_
    inline void addLife() { ++lives_; };                 // Increase lives_ (don't know when yet)
    inline void useZapper() { used_zapper_ = true; };    // Sets used_zapper_ to true
    inline void regenZapper() { used_zapper_ = false; }; // Sets used_zapper_ to false

    // Draw
    virtual void initModelPolygon() override;
};

#endif // PLAYER_H