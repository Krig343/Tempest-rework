#include "character.h"

//----------------------------- Constructors -----------------------------------

Character::Character(const bool &shooting,
                     const float &pos,
                     const int &lane) : is_shooting_{shooting},
                                        position_{pos},
                                        lane_{lane}
{
}

Character::Character(Character &c) : Character::Character(c.is_shooting_, c.lane_, c.position_)
{
}

//-------------------------- Caracter controls ---------------------------------

void Character::shoot(SDL_Renderer *renderer)
{
    is_shooting_ = true;
    // TODO : print the bullets and wait
    is_shooting_ = false;
}

void Character::move(const int &lane)
{
    lane_ = lane;
}

void Character::draw(SDL_Renderer *renderer, const float scale, const float angle, const SDL_Point position)
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