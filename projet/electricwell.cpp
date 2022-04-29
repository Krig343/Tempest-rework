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
    
    switch((level - 1)%4)
    {
        // Level 1
        case 0:
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

        // Level 2
        case 1:
            isCyclic_ = true;
            polygonSize_ = 16;
            color_ = {0, 0, 255, 255};

            backPolygon_.push_back({400,350});
            backPolygon_.push_back({375,350});
            backPolygon_.push_back({350,350});
            backPolygon_.push_back({350,325});
            backPolygon_.push_back({350,300});
            backPolygon_.push_back({350,275});
            backPolygon_.push_back({350,250});
            backPolygon_.push_back({375,250});
            backPolygon_.push_back({400,250});
            backPolygon_.push_back({425,250});
            backPolygon_.push_back({450,250});
            backPolygon_.push_back({450,275});
            backPolygon_.push_back({450,300});
            backPolygon_.push_back({450,325});
            backPolygon_.push_back({450,350});
            backPolygon_.push_back({425,350});

            frontPolygon_.push_back({400,500});
            frontPolygon_.push_back({300,500});
            frontPolygon_.push_back({200,500});
            frontPolygon_.push_back({200,400});
            frontPolygon_.push_back({200,300});
            frontPolygon_.push_back({200,200});
            frontPolygon_.push_back({200,100});
            frontPolygon_.push_back({300,100});
            frontPolygon_.push_back({400,100});
            frontPolygon_.push_back({500,100});
            frontPolygon_.push_back({600,100});
            frontPolygon_.push_back({600,200});
            frontPolygon_.push_back({600,300});
            frontPolygon_.push_back({600,400});
            frontPolygon_.push_back({600,500});
            frontPolygon_.push_back({500,500});
            break;

        // Level 3
        case 2:
            isCyclic_ = true;
            polygonSize_ = 16;
            color_ = {0, 0, 255, 255};

            backPolygon_.push_back({400,440});
            backPolygon_.push_back({392,440});
            backPolygon_.push_back({376,440});
            backPolygon_.push_back({360,440});
            backPolygon_.push_back({368,427});
            backPolygon_.push_back({376,414});
            backPolygon_.push_back({384,401});
            backPolygon_.push_back({392,388});
            backPolygon_.push_back({400,376});
            backPolygon_.push_back({408,389});
            backPolygon_.push_back({416,402});
            backPolygon_.push_back({424,415});
            backPolygon_.push_back({432,428});
            backPolygon_.push_back({440,440});
            backPolygon_.push_back({424,440});
            backPolygon_.push_back({408,440});

            frontPolygon_.push_back({400,500});
            frontPolygon_.push_back({350,500});
            frontPolygon_.push_back({250,500});
            frontPolygon_.push_back({150,500});
            frontPolygon_.push_back({200,420});
            frontPolygon_.push_back({250,340});
            frontPolygon_.push_back({300,260});
            frontPolygon_.push_back({350,180});
            frontPolygon_.push_back({400,100});
            frontPolygon_.push_back({450,180});
            frontPolygon_.push_back({500,260});
            frontPolygon_.push_back({550,340});
            frontPolygon_.push_back({600,420});
            frontPolygon_.push_back({650,500});
            frontPolygon_.push_back({550,500});
            frontPolygon_.push_back({450,500});
            break;

        // Level 4
        case 3:
            isCyclic_ = true;
            polygonSize_ = 16;
            color_ = {0, 0, 255, 255};

            backPolygon_.push_back({400,320});
            backPolygon_.push_back({395,315});
            backPolygon_.push_back({395,305});
            backPolygon_.push_back({385,305});
            backPolygon_.push_back({380,300});
            backPolygon_.push_back({385,295});
            backPolygon_.push_back({395,295});
            backPolygon_.push_back({395,285});
            backPolygon_.push_back({400,280});
            backPolygon_.push_back({405,285});
            backPolygon_.push_back({405,295});
            backPolygon_.push_back({415,295});
            backPolygon_.push_back({420,300});
            backPolygon_.push_back({415,305});
            backPolygon_.push_back({405,305});
            backPolygon_.push_back({405,315});

            frontPolygon_.push_back({400,500});
            frontPolygon_.push_back({350,450});
            frontPolygon_.push_back({350,350});
            frontPolygon_.push_back({250,350});
            frontPolygon_.push_back({200,300});
            frontPolygon_.push_back({250,250});
            frontPolygon_.push_back({350,250});
            frontPolygon_.push_back({350,150});
            frontPolygon_.push_back({400,100});
            frontPolygon_.push_back({450,150});
            frontPolygon_.push_back({450,250});
            frontPolygon_.push_back({550,250});
            frontPolygon_.push_back({600,300});
            frontPolygon_.push_back({550,350});
            frontPolygon_.push_back({450,350});
            frontPolygon_.push_back({450,450});
            break;
        default:
            break;
    }
}

void ElectricWell::highlightLane(SDL_Renderer *renderer, int lane)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

    SDL_RenderDrawLine(renderer, 
                       backPolygon_[lane].x,
                       backPolygon_[lane].y,
                       frontPolygon_[lane].x,
                       frontPolygon_[lane].y);

    SDL_RenderDrawLine(renderer, 
                       backPolygon_[(lane + 1)%polygonSize_].x,
                       backPolygon_[(lane + 1)%polygonSize_].y,
                       frontPolygon_[(lane + 1)%polygonSize_].x,
                       frontPolygon_[(lane + 1)%polygonSize_].y);   
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
