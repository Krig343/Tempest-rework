#ifndef ELECTRICWELL_H
#define ELECTRICWELL_H

#include <iostream> // string
#include <cstdlib>  // in & out -put
#include <SDL.h>    // graphical interface
#include <array>    // container array
#include <vector>   // container vector
#include <cmath>    // for M_PI (useless for now)
#include "lane.h"   // class lane

/* This class represents the the geometrical patern on whitch the player and the
 * ennemies evoluate. It has a unique color depending on the level, a shape and
 * the list of the lanes composing it
 */
class ElectricWell
{
private:
    std::array<Uint8, 4> color_;  // Container <r,g,b,a>
    std::string shape_;           // Maybe an enum. One of all shapes a well can have
    std::vector<Lane> lane_list_; // List of the lane composing the shape

public:
    // Constructors
    ElectricWell(const std::array<Uint8, 4> &color, const std::string &shape, const std::vector<Lane> &lanes);
    ~ElectricWell() = default;

    // Electric well controls
    void addLane(Vec2 x1, Vec2 y1, Vec2 x2, Vec2 y2);

    //Éventuellement supprimer paramètres
    void createCircle(int width, int height);     // Add lanes to create a circle
    void createSquare(int width, int height);     // Add lanes to create a square
    void createPlus(int width, int height);       // Add lanes to create a plus
    void createBinoculars(int width, int height); // Add lanes to create binoculars
    void createCross(int width, int height);      // Add lanes to create a cross
    void createTriangle(int width, int height);   // Add lanes to create a triangle
    void createX(int width, int height);          // Add lanes to create an X
    void createV(int width, int height);          // Add lanes to create a V
    void createStaires(int width, int height);    // Add lanes to create staires
    void createU(int width, int height);          // Add lanes to create a U
    void createFlat(int width, int height);       // Add lanes to create a plan
    void createHeart(int width, int height);      // Add lanes to create a heart
    void createStar(int width, int height);       // Add lanes to create a star
    void createW(int width, int height);          // Add lanes to create a W
    void createBird(int width, int height);       // Add lanes to create a bird
    void createInfinite(int width, int height);   // Add lanes to create an infinite symbole
    void draw(SDL_Renderer *renderer);            // Print the electric well in its color
};

#endif // ELECTRICWELL_H