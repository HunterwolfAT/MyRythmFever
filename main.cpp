#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>

#include "editor.h"



int main( int argc, char* args[] )
{
	// Start SDL
	if (SDL_Init( SDL_INIT_VIDEO ) < 0 && SDL_Init( SDL_INIT_AUDIO) < 0)
	{
		std::cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError()<<std::endl;
	} else {

		Editor editor;
		editor.loop();

		// Quit SDL
		SDL_Quit();
	}

	return 0;
}
