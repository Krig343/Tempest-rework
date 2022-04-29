#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream> // string
#include <cstdlib>  // in & out -put
#include <SDL.h>    // graphical interface
#include <array>    // container array
#include <vector>
#include <cmath>

/* The parent class for all the the characters, player and ennemies. The boolean
 * is_shooting_ is set to prevent the player to spam shooting, the position is
 * just the lane index in the electric_wells lane list and the color is and array
 */
class Character
{
public:
    bool isShooting_;  // True when player is shooting
    int lane_;         // The lane number
    float position_;

protected:
    std::vector<SDL_Point> modelPolygon_;
    std::array<Uint8, 4> modelColor_;

public:
    // Constructors
    Character(const bool &shooting, const int &lane, const float &pos);

    // Character controls
    void shoot(SDL_Renderer *renderer);      // Sets isShooting_ at true
    virtual void move(int movement, float speed, bool isCyclic, int polygonSize) = 0;  // Changes lane

    // Draw
    void draw(SDL_Renderer *renderer, const float scale, const float angle, const SDL_Point position);

protected:
    // Draw
    virtual void initModelPolygon() = 0;
};

#endif // CHARATER_H