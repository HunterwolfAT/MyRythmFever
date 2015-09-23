#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "editor.h"

/*
 * This are temporary variables to test out SDL_Mixer
 */
int result = 0;
int flags = MIX_INIT_MP3;

Editor::Editor() {
	ren = NULL;
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
		std::cout<<"CreateWindow Error!"<<std::endl;
		return 0;
	}

	ren = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if ( ren == NULL )
	{
		std::cout<<"CreateRenderer Error!"<<std::endl;
		return 0;
	}

	timeline.Init( WINDOW_HEIGHT );

	/*
	 * Test SDL_Mixer
	 */
	if ( flags != ( result = Mix_Init( flags ) ) )
	{
		std::cout<<"Could not initialize Mixer (result: "<<result<<")"<<std::endl;
		return 0;
	}

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *music = Mix_LoadMUS( "mrf_music.ogg" );
	if ( music == NULL )
	{
		std::cout<<"Could not load song!"<<std::endl;
		return 0;
	}
	//Mix_PlayMusic( music, 1 );

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
				if( event.type == SDL_KEYDOWN )
				{
					switch( event.key.keysym.sym )
					{
						case SDLK_ESCAPE:
							running = false;
							break;
					}
				}
				if( event.type == SDL_QUIT ) 
				{
					running = false;
				}
			}

			// Background Color
			SDL_SetRenderDrawColor( ren, 160, 0, 65, 255);
			SDL_RenderFillRect( ren, NULL);

			// Render Everything
			timeline.Render( ren );

			SDL_RenderPresent( ren );
		}

		SDL_DestroyWindow( window );
		//Mix_FreeMusic( music );
	}
}
