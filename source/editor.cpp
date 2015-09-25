#include "editor.h"


Editor::Editor() {
	ren = NULL;
	window = NULL;
	WINDOW_WIDTH = 1280;
	WINDOW_HEIGHT = 720;
	interface = new Interface( WINDOW_HEIGHT );
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

	//timeline.Init( WINDOW_HEIGHT );

	audioplayer.LoadSong("audio/mrf_music.ogg");
	audioplayer.PlaySong();

	return 1;
}

void Editor::loop() {
	
	if (!init())
	{
		std::cout<<"Editor Init Failed! SDL_Error: "<<SDL_GetError()<<std::endl;
	} else {
		std::cout<<"Editor Init Successful!"<<std::endl;
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
			interface->Render( ren );

			SDL_RenderPresent( ren );
		}

		SDL_DestroyWindow( window );
	}
}

Editor::~Editor() {
	delete interface;
}
