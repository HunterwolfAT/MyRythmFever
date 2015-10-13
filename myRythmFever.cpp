#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>

#include "source/editor.h"



int main( int argc, char* args[] )
{
    if ( argc > 1 )
    {
        // Start SDL
        if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)
        {
            std::cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError()<<std::endl;
        } else {

            Editor editor;
            editor.loop( args[1] );

            // Quit SDL
            SDL_Quit();
        }
    } else {
        std::cout<<"Please write a song in audio/ as an argument!"<<std::endl;
    }

	return 0;
}
