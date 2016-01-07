#include "editor.h"

Editor::Editor() {
	ren = NULL;
	window = NULL;

	globalproperties = new GlobalProperties( 720, 1280 );
	globalproperties->updateResolution( 1920, 1080 );

	interface = new Interface( globalproperties, &audioplayer );
}

int Editor::init( const char* songfiletitle ) {
	window = SDL_CreateWindow(
		"myRythmFever",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		globalproperties->get_scaled_window_width(),
		globalproperties->get_scaled_window_height(),
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
