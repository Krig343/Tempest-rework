#include "electricwell.h"

//----------------------------- Constructors -----------------------------------

ElectricWell::ElectricWell(const int &level) : level_{level}
{
    initLevelPolygons(level);
    initLevelLanes();
}

void ElectricWell::initLevelLanes()
{
    int p;

    for (p = 0; p < back_polygon_.size() - 1; p++)
    {
        lanes_.push_back(Lane(back_polygon_[p], back_polygon_[p + 1],
                              front_polygon_[p + 1], front_polygon_[p]));
    }

    if (is_cyclic_)
    {
        lanes_.push_back(Lane(back_polygon_[p], back_polygon_[0],
                              front_polygon_[0], front_polygon_[p]));
    }
}

void ElectricWell::initLevelPolygons(int level)
{

    switch ((level - 1) % 4)
    {
    // Level 1
    case 0:
        is_cyclic_ = true;
        polygon_size_ = 16;
        color_ = {0, 0, 255, 255};

        back_polygon_.push_back({400, 415});
        back_polygon_.push_back({385, 409});
        back_polygon_.push_back({373, 395});
        back_polygon_.push_back({366, 381});
        back_polygon_.push_back({364, 365});
        back_polygon_.push_back({368, 349});
        back_polygon_.push_back({375, 338});
        back_polygon_.push_back({387, 329});
        back_polygon_.push_back({400, 324});
        back_polygon_.push_back({413, 329});
        back_polygon_.push_back({425, 338});
        back_polygon_.push_back({432, 349});
        back_polygon_.push_back({436, 365});
        back_polygon_.push_back({434, 381});
        back_polygon_.push_back({427, 395});
        back_polygon_.push_back({415, 409});

        front_polygon_.push_back({400, 500});
        front_polygon_.push_back({338, 475});
        front_polygon_.push_back({285, 438});
        front_polygon_.push_back({240, 371});
        front_polygon_.push_back({224, 309});
        front_polygon_.push_back({227, 233});
        front_polygon_.push_back({255, 160});
        front_polygon_.push_back({326, 110});
        front_polygon_.push_back({400, 100});
        front_polygon_.push_back({474, 110});
        front_polygon_.push_back({545, 160});
        front_polygon_.push_back({573, 233});
        front_polygon_.push_back({576, 309});
        front_polygon_.push_back({560, 371});
        front_polygon_.push_back({515, 438});
        front_polygon_.push_back({462, 475});

        break;

    // Level 2
    case 1:
        is_cyclic_ = true;
        polygon_size_ = 16;
        color_ = {0, 0, 255, 255};

        back_polygon_.push_back({400, 350});
        back_polygon_.push_back({375, 350});
        back_polygon_.push_back({350, 350});
        back_polygon_.push_back({350, 325});
        back_polygon_.push_back({350, 300});
        back_polygon_.push_back({350, 275});
        back_polygon_.push_back({350, 250});
        back_polygon_.push_back({375, 250});
        back_polygon_.push_back({400, 250});
        back_polygon_.push_back({425, 250});
        back_polygon_.push_back({450, 250});
        back_polygon_.push_back({450, 275});
        back_polygon_.push_back({450, 300});
        back_polygon_.push_back({450, 325});
        back_polygon_.push_back({450, 350});
        back_polygon_.push_back({425, 350});

        front_polygon_.push_back({400, 500});
        front_polygon_.push_back({300, 500});
        front_polygon_.push_back({200, 500});
        front_polygon_.push_back({200, 400});
        front_polygon_.push_back({200, 300});
        front_polygon_.push_back({200, 200});
        front_polygon_.push_back({200, 100});
        front_polygon_.push_back({300, 100});
        front_polygon_.push_back({400, 100});
        front_polygon_.push_back({500, 100});
        front_polygon_.push_back({600, 100});
        front_polygon_.push_back({600, 200});
        front_polygon_.push_back({600, 300});
        front_polygon_.push_back({600, 400});
        front_polygon_.push_back({600, 500});
        front_polygon_.push_back({500, 500});
        break;

    // Level 3
    case 2:
        is_cyclic_ = true;
        polygon_size_ = 16;
        color_ = {0, 0, 255, 255};

        back_polygon_.push_back({400, 440});
        back_polygon_.push_back({392, 440});
        back_polygon_.push_back({376, 440});
        back_polygon_.push_back({360, 440});
        back_polygon_.push_back({368, 427});
        back_polygon_.push_back({376, 414});
        back_polygon_.push_back({384, 401});
        back_polygon_.push_back({392, 388});
        back_polygon_.push_back({400, 376});
        back_polygon_.push_back({408, 389});
        back_polygon_.push_back({416, 402});
        back_polygon_.push_back({424, 415});
        back_polygon_.push_back({432, 428});
        back_polygon_.push_back({440, 440});
        back_polygon_.push_back({424, 440});
        back_polygon_.push_back({408, 440});

        front_polygon_.push_back({400, 500});
        front_polygon_.push_back({350, 500});
        front_polygon_.push_back({250, 500});
        front_polygon_.push_back({150, 500});
        front_polygon_.push_back({200, 420});
        front_polygon_.push_back({250, 340});
        front_polygon_.push_back({300, 260});
        front_polygon_.push_back({350, 180});
        front_polygon_.push_back({400, 100});
        front_polygon_.push_back({450, 180});
        front_polygon_.push_back({500, 260});
        front_polygon_.push_back({550, 340});
        front_polygon_.push_back({600, 420});
        front_polygon_.push_back({650, 500});
        front_polygon_.push_back({550, 500});
        front_polygon_.push_back({450, 500});
        break;

    // Level 4
    case 3:
        is_cyclic_ = true;
        polygon_size_ = 16;
        color_ = {0, 0, 255, 255};

        back_polygon_.push_back({400, 320});
        back_polygon_.push_back({395, 315});
        back_polygon_.push_back({395, 305});
        back_polygon_.push_back({385, 305});
        back_polygon_.push_back({380, 300});
        back_polygon_.push_back({385, 295});
        back_polygon_.push_back({395, 295});
        back_polygon_.push_back({395, 285});
        back_polygon_.push_back({400, 280});
        back_polygon_.push_back({405, 285});
        back_polygon_.push_back({405, 295});
        back_polygon_.push_back({415, 295});
        back_polygon_.push_back({420, 300});
        back_polygon_.push_back({415, 305});
        back_polygon_.push_back({405, 305});
        back_polygon_.push_back({405, 315});

        front_polygon_.push_back({400, 500});
        front_polygon_.push_back({350, 450});
        front_polygon_.push_back({350, 350});
        front_polygon_.push_back({250, 350});
        front_polygon_.push_back({200, 300});
        front_polygon_.push_back({250, 250});
        front_polygon_.push_back({350, 250});
        front_polygon_.push_back({350, 150});
        front_polygon_.push_back({400, 100});
        front_polygon_.push_back({450, 150});
        front_polygon_.push_back({450, 250});
        front_polygon_.push_back({550, 250});
        front_polygon_.push_back({600, 300});
        front_polygon_.push_back({550, 350});
        front_polygon_.push_back({450, 350});
        front_polygon_.push_back({450, 450});
        break;
    default:
        break;
    }
}

void ElectricWell::highlightLane(SDL_Renderer *renderer, int lane)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

    SDL_RenderDrawLine(renderer,
                       back_polygon_[lane].x,
                       back_polygon_[lane].y,
                       front_polygon_[lane].x,
                       front_polygon_[lane].y);

    SDL_RenderDrawLine(renderer,
                       back_polygon_[(lane + 1) % polygon_size_].x,
                       back_polygon_[(lane + 1) % polygon_size_].y,
                       front_polygon_[(lane + 1) % polygon_size_].x,
                       front_polygon_[(lane + 1) % polygon_size_].y);
}

void ElectricWell::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, color_[0], color_[1], color_[2], color_[3]);

    // Draw polygons
    SDL_RenderDrawLines(renderer, &back_polygon_[0], polygon_size_);
    SDL_RenderDrawLines(renderer, &front_polygon_[0], polygon_size_);

    // Closing polygons if level is cyclic
    if (is_cyclic_)
    {
        SDL_RenderDrawLine(renderer,
                           back_polygon_[polygon_size_ - 1].x,
                           back_polygon_[polygon_size_ - 1].y,
                           back_polygon_[0].x,
                           back_polygon_[0].y);

        SDL_RenderDrawLine(renderer,
                           front_polygon_[polygon_size_ - 1].x,
                           front_polygon_[polygon_size_ - 1].y,
                           front_polygon_[0].x,
                           front_polygon_[0].y);
    }

    // Draw lanes between polygons
    for (std::uint8_t p = 0; p < polygon_size_; p++)
    {
        SDL_RenderDrawLine(renderer,
                           back_polygon_[p].x,
                           back_polygon_[p].y,
                           front_polygon_[p].x,
                           front_polygon_[p].y);
    }
}
