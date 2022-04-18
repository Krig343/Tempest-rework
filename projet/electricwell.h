#ifndef ELECTRICWELL_H
#define ELECTRICWELL_H

#include <vector> // container vector
#include "lane.h" // class lane

/* This class represents the the geometrical patern on whitch the player and the
 * ennemies evoluate. It has a unique color depending on the level, a shape and
 * the list of the lanes composing it
 */
class ElectricWell
{
public:
    std::array<Uint8, 4> color_; // Container <r,g,b,a>
    std::string shape_;          // One of all shapes a well can have
private:
    std::vector<Lane> lane_list_; // List of the lane composing the shape

public:
    // Constructors
    ElectricWell(const std::array<Uint8, 4> &color, const std::string &shape, const std::vector<Lane> &lanes);

    // Electric well controls
    void addLane(Vec2 x1, Vec2 y1, Vec2 x2, Vec2 y2); // Adds a lane composed of x1, y1, x2, y2 to the lane_list_

    //Éventuellement supprimer paramètres
    void createCircle();               // Adds lanes to create a circle
    void createSquare();               // Adds lanes to create a square
    void createPlus();                 // Adds lanes to create a plus
    void createBinoculars();           // Adds lanes to create binoculars
    void createCross();                // Adds lanes to create a cross
    void createTriangle();             // Adds lanes to create a triangle
    void createX();                    // Adds lanes to create an X
    void createV();                    // Adds lanes to create a V
    void createStaires();              // Adds lanes to create staires
    void createU();                    // Adds lanes to create a U
    void createFlat();                 // Adds lanes to create a plan
    void createHeart();                // Adds lanes to create a heart
    void createStar();                 // Adds lanes to create a star
    void createW();                    // Adds lanes to create a W
    void createBird();                 // Adds lanes to create a bird
    void createInfinite();             // Adds lanes to create an infinite symbole
    void draw(SDL_Renderer *renderer); // Print the electric well in its color
};

#endif // ELECTRICWELL_H