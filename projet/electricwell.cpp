#include "electricwell.h"

//----------------------------- Constructors -----------------------------------

ElectricWell::ElectricWell(const int level) : level_{level}
{
    initLevelPolygons(level);
    initLevelLanes();
}

void ElectricWell::initLevelLanes()
{
    int p;

    for(p = 0; p < backPolygon_.size() - 1; p++){
        lanes_.push_back(Lane(backPolygon_[p], backPolygon_[p + 1],
                             frontPolygon_[p + 1], frontPolygon_[p]));
    }

    if(isCyclic_){
        lanes_.push_back(Lane(backPolygon_[p], backPolygon_[0],
                              frontPolygon_[0], frontPolygon_[p]));
    }
}

void ElectricWell::initLevelPolygons(int level)
{
    switch(level)
    {
        case 1:
            isCyclic_ = true;
            polygonSize_ = 16;
            color_ = {0, 0, 255, 255};

            backPolygon_.push_back({400,415});
            backPolygon_.push_back({385,409});
            backPolygon_.push_back({373,395});
            backPolygon_.push_back({366,381});
            backPolygon_.push_back({364,365});
            backPolygon_.push_back({368,349});
            backPolygon_.push_back({375,338});
            backPolygon_.push_back({387,329});
            backPolygon_.push_back({400,324});
            backPolygon_.push_back({413,329});
            backPolygon_.push_back({425,338});
            backPolygon_.push_back({432,349});
            backPolygon_.push_back({436,365});
            backPolygon_.push_back({434,381});
            backPolygon_.push_back({427,395});
            backPolygon_.push_back({415,409});

            frontPolygon_.push_back({400,500});
            frontPolygon_.push_back({338,475});
            frontPolygon_.push_back({285,438});
            frontPolygon_.push_back({240,371});
            frontPolygon_.push_back({224,309});
            frontPolygon_.push_back({227,233});
            frontPolygon_.push_back({255,160});
            frontPolygon_.push_back({326,110});
            frontPolygon_.push_back({400,100});
            frontPolygon_.push_back({474,110});
            frontPolygon_.push_back({545,160});
            frontPolygon_.push_back({573,233});
            frontPolygon_.push_back({576,309});
            frontPolygon_.push_back({560,371});
            frontPolygon_.push_back({515,438});
            frontPolygon_.push_back({462,475});

            break;
        default:
            break;
    }
}

void ElectricWell::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, color_[0], color_[1], color_[2], color_[3]);

    // Draw polygons
    SDL_RenderDrawLines(renderer, &backPolygon_[0], polygonSize_);
    SDL_RenderDrawLines(renderer, &frontPolygon_[0], polygonSize_);
    
    // Closing polygons if level is cyclic
    if(isCyclic_)
    {
        SDL_RenderDrawLine(renderer, 
                           backPolygon_[polygonSize_ - 1].x,
                           backPolygon_[polygonSize_ - 1].y,
                           backPolygon_[0].x,
                           backPolygon_[0].y);

        SDL_RenderDrawLine(renderer, 
                           frontPolygon_[polygonSize_ - 1].x,
                           frontPolygon_[polygonSize_ - 1].y,
                           frontPolygon_[0].x,
                           frontPolygon_[0].y);
    }

    // Draw lanes between polygons
    for(std::uint8_t p = 0; p < polygonSize_; p++)
    {
        SDL_RenderDrawLine(renderer, 
                           backPolygon_[p].x,
                           backPolygon_[p].y,
                           frontPolygon_[p].x,
                           frontPolygon_[p].y);
    }
}
