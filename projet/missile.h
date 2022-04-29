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
    bool dead_;

protected:
    std::vector<SDL_Point> model_polygon_;
    std::array<Uint8, 4> model_color_;

public:
    // Constructors
    Missile(const int &lane, const float &pos);

    // Missile controls
    void move();
    inline void kill() { dead_ = true; };

    // IO
    void initModelPolygon();
    void draw(SDL_Renderer *renderer, const float scale, const float angle, const SDL_Point position);
};

#endif // MISSILE_H