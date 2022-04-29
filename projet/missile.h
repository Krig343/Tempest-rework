#ifndef MISSILE_H
#define MISSILE_H

#include <SDL.h> // graphical interface
#include <vector> 
#include <array>
#include <cmath>

class Missile
{
public:
    int lane_;
    float position_;

protected:
    std::vector<SDL_Point> modelPolygon_;
    std::array<Uint8, 4> modelColor_;

public:
    // Constructors
    Missile(const int &lane, const float &pos);

    // Missile controls
    void move();

    // Draw
    void initModelPolygon();
    void draw(SDL_Renderer *renderer, const float scale, const float angle, const SDL_Point position);
};

#endif // MISSILE_H