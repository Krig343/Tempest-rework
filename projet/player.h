#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character
{
private:
    int lives_;        // Player's lives number
    bool used_zapper_; // True if player used his zapper

public:
    // Constructors
    Player(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const int &life, const bool &zapper);
    ~Player() = default;

    // Player controls
    void loseLife();       // Decrease lives_
    void addLife();        // Increase lives_ (don't know when yet)
    void useZapper();      // Sets used_zapper_ to true
    void regenZapper();    // Sets used_zapper_ to false
    void zapperModifier(); // Checks used_zapper_'s current state and calls on top functions
};

#endif // PLAYER_H