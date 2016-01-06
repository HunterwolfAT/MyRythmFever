#include "editor.h"


Editor::Editor() {
	ren = NULL;
	window = NULL;
	int base_window_width = 1280;	// Base resolution. If window size differs, scale.
	int base_window_height = 720;
	WINDOW_WIDTH = 1920;		// That needs to be loaded from a global config savefile
	WINDOW_HEIGHT = 1080;		// That needs to be loaded from a global config savefile
	screenscale_factor = WINDOW_HEIGHT / base_window_height;
	scaled_window_width = base_window_width * screenscale_factor;
	scaled_window_height = base_window_height * screenscale_factor;
	interface = new Interface( scaled_window_height, &audioplayer );
}

int Editor::init( const char* songfiletitle ) {
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

    std::cout<<"Trying to load song "<<songfiletitle<<"."<<std::endl;
    std::string songfile_str = songfiletitle;
    std::string songfile = "audio/" + songfile_str;
	audioplayer.LoadSong( songfile.c_str() );

	return 1;
}

void Editor::loop( const char* songfiletitle ) {

	if (!init( songfiletitle ))
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

						case SDLK_SPACE:
							audioplayer.PausePlaySong();
							break;
					}
				}
				if( event.type == SDL_QUIT )
				{
					running = false;
				}
			}

			// Update cycle
			audioplayer.Update();
			interface->Update();

			// Background Color
			SDL_SetRenderDrawColor( ren, 160, 0, 65, 255);
			//SDL_RenderFillRect( ren, NULL);
			SDL_RenderClear( ren );

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
