#ifndef LANE_H
#define LANE_H

#include <array>    // container array
#include <iostream> // sring
#include <cstdlib>  // in & out -put
#include <SDL.h>    // graphical interface
#include <cmath>


/* A lane is a combination of 4 points (Vec2) and that has a color depending if
 * the player is on it, if a pulsar used pulse or if none of these
 */
class Lane
{
private:
    SDL_Point laneDirection_;

    SDL_Point frontMiddle_;
    SDL_Point backMiddle_;
    
    float laneAngle_;
    
    float frontSize_;
    float backSize_;

public:
    // Constructors
    Lane(const SDL_Point &f1, const SDL_Point &f2, const SDL_Point &b3, const SDL_Point &b4);

    float getScale(const float position);
    float getAngle();
    SDL_Point getPosition(const float position);
};

#endif // LANE_H