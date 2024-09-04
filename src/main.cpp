
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#include "app.hpp"
#include "sprite.hpp"
#include "draw.hpp"

using namespace std;

int main(){
    cout << "Program started" << endl;

    if (!init()){
        return 1;
    }
    
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
        drawScene();
        SDL_RenderPresent(App.renderer);
    }

    deinit();
    return 0;
}
