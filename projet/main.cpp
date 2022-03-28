#include <SDL.h> // Maybe moving it deeper
#include <assert.h>

#include "game.h"

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
    // Test de draw un circle
    std::vector<Lane> list;
    std::array<Uint8, 4> Color = {0, 255, 0, 255};
    ElectricWell ew{Color, "circle", list};
    ew.createCircle(width, height);

    bool quit = false;
    while (!quit)
    {
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
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        fullscreen = true;
                    }
                    else
                    {
                        SDL_SetWindowFullscreen(window, 0);
                        fullscreen = false;
                    }
                }
                break;
            }
        }

        // Game loop
        ew.draw(renderer); // TESTS
        SDL_RenderPresent(renderer);
    }
    SDL_Quit();
    return 0;
}