#include "character.h"

//----------------------------- Constructors -----------------------------------

Character::Character(const bool &shooting, 
                     const int &lane, 
                     const float &pos) : isShooting_{shooting},
                                         lane_{lane},
                                         position_{pos}                       
{
}

//-------------------------- Caracter controls ---------------------------------

void Character::shoot(SDL_Renderer *renderer)
{
    isShooting_ = true;
    // TODO : print the bullets and wait
    isShooting_ = false;
}

void Character::draw(SDL_Renderer *renderer, const float scale, const float angle, const SDL_Point position)
{
    std::vector<SDL_Point> scaledModel;
    std::vector<SDL_Point> rotatedModel;
    std::vector<SDL_Point> translatedModel;

    // Scaling
    for(auto p : modelPolygon_)
        scaledModel.push_back({p.x*scale/10.0,
                               p.y*scale/10.0});
    
    // Rotating
    for(auto p : scaledModel)
        rotatedModel.push_back({p.x*cos(angle) - p.y*sin(angle),
                                p.x*sin(angle) + p.y*cos(angle)});

    // Translating
    for(auto p : rotatedModel)
        translatedModel.push_back({p.x + position.x,
                                   p.y + position.y});

    SDL_SetRenderDrawColor(renderer, 
                           modelColor_[0],
                           modelColor_[1],
                           modelColor_[2],
                           modelColor_[3]);

    SDL_RenderDrawLines(renderer, &translatedModel[0], translatedModel.size());
}