#include <SDL2/SDL.h>
#include <iostream>
#include "editor.h"

Editor::Editor() {
	screenSurface = NULL;
	window = NULL;
	WINDOW_WIDTH = 1280;
	WINDOW_HEIGHT = 720;
}

void Editor::test() {
	std::cout<<"Testing...!"<<std::endl;
}

int Editor::init() {
	window = SDL_CreateWindow(
		"myRythmFever",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN );

	if ( window == NULL ) 
	{
		return 0;
	}

	screenSurface = SDL_GetWindowSurface( window );

	return 1;
}

void Editor::loop() {
	
	if (!init())
	{
		std::cout<<"Editor Init Failed! SDL_Error: "<<SDL_GetError()<<std::endl;
	} else {
		while ( running ) 
		{
			while( SDL_PollEvent( &event ) != 0 )
			{
				if( event.type == SDL_QUIT ) 
				{
					running = false;
				}
			}

			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 180, 65, 0));
			SDL_UpdateWindowSurface( window );
		}

		SDL_DestroyWindow( window );
	}
}
