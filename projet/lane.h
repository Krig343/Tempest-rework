#ifndef LANE_H
#define LANE_H

#include <utility> // container pair
#include <array>   // container array
#include <iostream>
#include <cstdlib>
#include <SDL.h>

using Vec2 = std::pair<int, int>;

class Lane
{
private:
    Vec2 player_begin_point_;    // First point of the lane, player side
    Vec2 player_end_point_;      // Second point of the lane, player side
    Vec2 ennemi_begin_point_;    // First point of the lane, ennemi side
    Vec2 ennemi_end_point_;      // Second point of the lane, ennemi side
    std::array<Uint8, 4> color_; // Container <r,g,b,a>

public:
    // Constructors
    Lane(const Vec2 &pp1, const Vec2 &pp2, const Vec2 &ep1, const Vec2 &ep2, std::array<Uint8, 4> color);
    ~Lane() = default;

    // Lane controls
    void drawLane(SDL_Renderer *renderer);
    // void updateCoord(SDL_Window *window);
};

#endif // LANE_H