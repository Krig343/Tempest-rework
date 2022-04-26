#ifndef CARACTER_H
#define CARACTER_H

#include <iostream> // string
#include <cstdlib>  // in & out -put
#include <SDL.h>    // graphical interface
#include <utility>  // container pair
#include <array>    // container array

/* The parent class for all the the characters, player and ennemies. The boolean
 * is_shooting_ is set to prevent the player to spam shooting, the position is
 * just the lane index in the electric_wells lane list and the color is and array
 */
class Character
{
public:
    bool is_shooting_;           // True when player is shooting
    int position_;               // The 2D position (needs to be fixed)
    int lane_number_;            // The lane number
    std::array<Uint8, 4> color_; // Container <r,g,b,a>

public:
    // Constructors
    Character(const bool &shooting, const int &pos, const int &lane, const std::array<Uint8, 4> &color);
    Character(Character &car);

    // Caracter controls
    void shoot(SDL_Renderer *renderer); // Sets is_shooting_ at true
    void move(const int &pos);          // Changes position_ according to the sign of pos

    // IO
    void drawCaracter(SDL_Renderer *renderer); // Prints the caracter on its position in its color
};

#endif // CARATER_H