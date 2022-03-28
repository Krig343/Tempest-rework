#ifndef ELECTRICWELL_H
#define ELECTRICWELL_H

#include <iostream> // string
#include <cstdlib>  // in & out -put
#include <SDL.h>    // graphical interface
#include <array>    // container array
#include <vector>   // container vector
#include <cmath>
#include "lane.h" // classe lane

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
    void createCircle(int width, int height);
    void createSquare(int width, int height);
    void createPlus(int width, int height);
    void createBinoculars(int width, int height);
    void createCross(int width, int height);
    void createTriangle(int width, int height);
    void createX(int width, int height);
    void createV(int width, int height);
    void createStaires(int width, int height);
    void createU(int width, int height);
    void createFlat(int width, int height);
    void createHeart(int width, int height);
    void createStar(int width, int height);
    void createW(int width, int height);
    void createBird(int width, int height);
    void createInfinite(int width, int height);
    void draw(SDL_Renderer *renderer);
};

#endif // ELECTRICWELL_H