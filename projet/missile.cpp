#include "missile.h"
#include <iostream>
//----------------------------- Constructors -----------------------------------

Missile::Missile(const int &lane, const float &pos) : lane_{lane},
                                                      position_{pos}
{
    initModelPolygon();
    dead_ = false;
}

//--------------------------- Missile controls ---------------------------------

void Missile::move()
{
    // Missile speed
    position_ += 0.015;

    // Dead when crossing the horizon
    if (position_ > 1.0)
        kill();
}

//--------------------------------- IO -----------------------------------------

void Missile::initModelPolygon()
{
    model_color_ = {255, 255, 255, 255};

    model_polygon_.push_back({0, -1});
    model_polygon_.push_back({-1, 0});
    model_polygon_.push_back({0, 1});
    model_polygon_.push_back({1, 0});
    model_polygon_.push_back({0, -1});
}

void Missile::draw(SDL_Renderer *renderer, const float scale, const float angle, const SDL_Point position)
{
    std::vector<SDL_Point> scaledModel;
    std::vector<SDL_Point> rotatedModel;
    std::vector<SDL_Point> translatedModel;

    // Scaling
    for (auto p : model_polygon_)
        scaledModel.push_back({p.x * scale / 10.0,
                               p.y * scale / 10.0});

    // Rotating
    for (auto p : scaledModel)
        rotatedModel.push_back({p.x * cos(angle) - p.y * sin(angle),
                                p.x * sin(angle) + p.y * cos(angle)});

    // Translating
    for (auto p : rotatedModel)
        translatedModel.push_back({p.x + position.x,
                                   p.y + position.y});

    SDL_SetRenderDrawColor(renderer,
                           model_color_[0],
                           model_color_[1],
                           model_color_[2],
                           model_color_[3]);

    SDL_RenderDrawLines(renderer, &translatedModel[0], translatedModel.size());
}