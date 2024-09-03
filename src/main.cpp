
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#include "app.hpp"
#include "sprite.hpp"

using namespace std;

int main(){
    cout << "Program started" << endl;

    if (!init()){
        return 1;
    }

    Sprite t("assets/Ketonian-flag.png");
    

    while (true){
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(App.renderer, 96, 128, 255, 255);
        SDL_RenderClear(App.renderer);
        t.draw(0,0);
        SDL_RenderPresent(App.renderer);
    }

    deinit();
    return 0;
}
