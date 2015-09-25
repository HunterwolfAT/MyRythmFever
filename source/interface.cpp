#include "interface.h"

Interface::Interface( int windowheight )
{
	ifont = NULL;
	timeline.Init( windowheight );

	if ( TTF_Init() < 0 )
	{
		std::cout<<"SDL_TTF was not initialized! SDL_ERROR: "<<TTF_GetError()<<std::endl;
	} else {
		ifont = TTF_OpenFont("font.ttf", 16);
		if ( ifont == NULL )
		{
			std::cout<<"Font could not be loaded! SDL_ERROR: "<<TTF_GetError()<<std::endl;
		}
	}
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
