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
    std::array<Uint8, 4> color_;
    int level_;
    int polygonSize_;

    bool isCyclic_;
    
    std::vector<SDL_Point> backPolygon_;
    std::vector<SDL_Point> frontPolygon_;

    std::vector<Lane> lanes_;

private:
    void initLevelPolygons(int level);
    void initLevelLanes();
    
public:
    // Constructors
    ElectricWell(int level);
    
    // Draw
    void highlightLane(SDL_Renderer *renderer, int lane);
    void draw(SDL_Renderer *renderer); // Print the electric well in its color
};

#endif // ELECTRICWELL_H