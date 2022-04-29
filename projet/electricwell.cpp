#include "electricwell.h"

//----------------------------- Constructors -----------------------------------

ElectricWell::ElectricWell(const int &level, const std::string &shape) : level_{level},
                                                                         shape_{shape}
{
    initLevelPolygons(shape);
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

const int ElectricWell::resolve(std::string shape)
{
    static const std::map<std::string, int> typeStrings{
        {"Circle", 1},
        {"Square", 2},
        {"Plus", 3},
        {"Binoculars", 4},
        {"Cross", 5},
        {"Triangle", 6},
        {"X", 7},
        {"V", 8},
        {"Staires", 9},
        {"U", 10},
        {"Flat", 11},
        {"Heart", 12},
        {"Star", 13},
        {"W", 14},
        {"Bird", 15},
        {"Infinite", 16}};

    auto itr = typeStrings.find(shape);
    if (itr != typeStrings.end())
    {
        return itr->second;
    }
    std::cout << "La forme " << shape << " n'existe pas" << std::endl;
    exit(EXIT_FAILURE);
}

void ElectricWell::initLevelPolygons(std::string shape)
{
    switch (resolve(shape))
    {
    case 1:
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
