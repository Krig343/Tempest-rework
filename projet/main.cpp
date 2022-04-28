#include <SDL.h> // Maybe moving it deeper
#include <assert.h>

#include "game.h"

void prepareFullscreen(SDL_Window *window, SDL_Renderer *renderer, const int &flag)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetWindowFullscreen(window, flag);
}

void applyFullscreen(SDL_Window *window, SDL_Renderer *renderer, const int &width, const int &height, const int &w, const int &h, ElectricWell &ew)
{
    SDL_Rect rect{(w - width) / 2, (h - height) / 2, width, height};
    SDL_RenderSetViewport(renderer, &rect);
    ew.draw(renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Pb init SDL" << std::endl;
        return 0;
    }

    int width = 800;
    int height = 600;
    bool fullscreen = false;
    SDL_Window *window = SDL_CreateWindow("Tempest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    assert(renderer != NULL);

    // Init game components
    // Draw a square test
    std::vector<Lane> list;
    std::array<Uint8, 4> Color = {0, 0, 255, 255};
    ElectricWell ew{Color, "square", list};

    Player player{false, 1, 1, Color, 1, false};

    // std::vector<Ennemi> ennemi_list;

    Game game{player, ew, 1, 0};
    game.electric_well_.createSquare();

    bool quit = false;
    while (!quit)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT: // Quits with the window cross
                quit = true;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) // Press "escape" to quit
                    quit = true;
                if (event.key.keysym.sym == SDLK_f) // Press "f" to toggle fullscreen
                {
                    if (!fullscreen)
                    {
                        prepareFullscreen(window, renderer, SDL_WINDOW_FULLSCREEN);
                        int w, h;
                        SDL_GetWindowSize(window, &w, &h);
                        applyFullscreen(window, renderer, width, height, w, h, ew);
                        fullscreen = true;
                    }
                    else
                    {
                        prepareFullscreen(window, renderer, 0);
                        SDL_SetWindowSize(window, width, height);
                        applyFullscreen(window, renderer, width, height, width, height, ew);
                        fullscreen = false;
                    }
                }
                // if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_q)
                //     game.player_.move(1);
                // if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
                //     game.player_.move(-1);
                break;
            }
        }

        // Game loop
        game.printScore(renderer);
        game.printLevel(renderer);
        game.electric_well_.draw(renderer);
        game.printAvoidSpikes(renderer);
        game.score_ = (game.score_ + 1) % 999999;
        SDL_RenderPresent(renderer);
    }
    SDL_Quit();
    return 0;
}