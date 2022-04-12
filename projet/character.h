#ifndef CARACTER_H
#define CARACTER_H

#include <iostream> // string
#include <cstdlib>  // in & out -put
#include <SDL.h>    // graphical interface
#include <utility>  // container pair
#include <array>    // container array

class Character
{
protected:
    bool is_shooting_;           // True when player is shooting
    int position_;               // Lane number
    std::array<Uint8, 4> color_; // Container <r,g,b,a>

public:
    static int index_; // Global index for all characters

public:
    // Constructors
    Character(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color);
    Character(const Character &car);
    ~Character();

    // Caracter controls
    void shoot(SDL_Renderer *renderer); // Sets is_shooting_ at true
    void move(const int *pos);          // changes position_ to pos

    // IO
    void drawCaracter(SDL_Renderer *renderer); // print the caracter on its position in its color
};

#endif // CARATER_H