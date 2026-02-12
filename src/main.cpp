
#include "core/Timer.h"
#include <SDL.h>
#include <SDL_error.h>

#include <iostream>
#include <ostream>
#include "pTS/pTSpace.h"

int main(int argc, char* argv[]) {

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init:" << SDL_GetError() << std::endl;
    }
    // Create Window
    SDL_Window *win = SDL_CreateWindow("Hello pTSDL2", 100, 100, 1280, 720, SDL_WINDOW_OPENGL);

    if (win == nullptr) {
        std::cerr << "SDL Error:" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create Renderer
    auto ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(ren == nullptr) {
        SDL_DestroyWindow(win);
        std::cerr << "SDL Renderer error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    //Create a single event loop
    SDL_SetRenderDrawColor(ren, 40, 40, 60, 255);
    SDL_RenderClear(ren);

    bool quit = false;
    SDL_Event event;

    pTS::Engine::get_instance()->log();

    while(!quit) {
        while (SDL_PollEvent(&event)) {
            pTS::Timer::get_instance()->log();
            if(event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }
        }
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
