#ifndef ELECTRICWELL_H
#define ELECTRICWELL_H

#include <vector> // container vector
#include "lane.h" // class lane
#include <map>

/* This class represents the the geometrical patern on whitch the player and the
 * ennemies evoluate. It has a unique color depending on the level, a shape and
 * the list of the lanes composing it
 */
class ElectricWell
{
public:
    std::array<Uint8, 4> color_;
    int level_;
    std::string shape_;
    int polygon_size_;
    bool is_cyclic_;
    std::vector<SDL_Point> back_polygon_;
    std::vector<SDL_Point> front_polygon_;
    std::vector<Lane> lanes_;

public:
    // Constructors
    ElectricWell(const int &level, const std::string &shape);

private:
    void initLevelPolygons(std::string shape);
    void initLevelLanes();
    const int resolve(std::string shape);

public:
    // Constructors
    ElectricWell(int level);

    // Draw
    void highlightLane(SDL_Renderer *renderer, int lane);
    void draw(SDL_Renderer *renderer); // Print the electric well in its color
};

#endif // ELECTRICWELL_H