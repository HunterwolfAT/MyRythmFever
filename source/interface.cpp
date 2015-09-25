#include "interface.h"

Interface::Interface( int windowheight )
{
	// Initialize SDL_TTF to render Text
	ifont = NULL;

	if ( TTF_Init() < 0 )
	{
		std::cout<<"SDL_TTF was not initialized! SDL_ERROR: "<<TTF_GetError()<<std::endl;
	} else {
		ifont = TTF_OpenFont("img/font.ttf", 116);
		if ( ifont == NULL )
		{
			std::cout<<"Font could not be loaded! SDL_ERROR: "<<TTF_GetError()<<std::endl;
		}
	}

	// Initialize Interface Components
	timeline.Init( windowheight, ifont );
}

void Interface::Render( SDL_Renderer* ren )
{
	timeline.Render( ren );
}

Interface::~Interface()
{
	TTF_CloseFont(ifont);
	ifont = NULL;
}
