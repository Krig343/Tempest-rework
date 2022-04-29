#include <SDL.h> // Maybe moving it deeper
#include <assert.h>

#include "game.h"

void prepareFullscreen(SDL_Window *window, SDL_Renderer *renderer, const int &flag)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetWindowFullscreen(window, flag);
}

void applyFullscreen(SDL_Window *window, SDL_Renderer *renderer, const int &width, const int &height, const int &w, const int &h, Game game)
{
    SDL_Rect rect{(w - width) / 2, (h - height) / 2, width, height};
    SDL_RenderSetViewport(renderer, &rect);
    game.draw(renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL initialization failed" << std::endl;
        return 0;
    }

    int width = 800;
    int height = 600;
    bool fullscreen = false;
    SDL_Window *window = SDL_CreateWindow("Tempest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    assert(renderer != NULL);

    bool quit = false;

    Game g{};

    while (!quit)
    {
        g.draw(renderer);

        SDL_Event event;

        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT: // Quits with the window cross
                quit = true;
                break;
            case SDL_KEYDOWN:
                // Escape to quit
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;

                // f to toggle fullscreen
                if (event.key.keysym.sym == SDLK_f)
                {
                    if (!fullscreen)
                    {
                        prepareFullscreen(window, renderer, SDL_WINDOW_FULLSCREEN);
                        int w, h;
                        SDL_GetWindowSize(window, &w, &h);
                        applyFullscreen(window, renderer, width, height, w, h, g);
                        fullscreen = true;
                    }
                    else
                    {
                        prepareFullscreen(window, renderer, 0);
                        SDL_SetWindowSize(window, width, height);
                        applyFullscreen(window, renderer, width, height, width, height, g);
                        fullscreen = false;
                    }
                }

                // Left or q to move clockwise
                if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_q)
                    g.player_.move(1, 1.0, g.electric_well_.isCyclic_, g.electric_well_.polygonSize_);

                // Right or d to move anti-clockwise
                if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
                    g.player_.move(-1, 1.0, g.electric_well_.isCyclic_, g.electric_well_.polygonSize_);

                // Space to fire
                if (event.key.keysym.sym == SDLK_SPACE)
                    g.addPlayerMissile(g.player_.lane_);

                break;
            }
        }

        // Game loop
        g.update();
        quit = g.endGame();
    }

    std::cout << "Final score : " << g.score_ << std::endl;

    SDL_Quit();
    return 0;
}