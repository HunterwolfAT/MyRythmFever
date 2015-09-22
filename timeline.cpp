#include "timeline.h"


void Timeline::Init( int windowHeight ) 
{
	width = 1280;
	height = 100;
	int marker = 0;

	background.w = width;
	background.h = height;
	background.x = 0;
	background.y = windowHeight - height;
}

void Timeline::Render( SDL_Renderer *ren )
{
	SDL_SetRenderDrawColor( ren, 210, 60, 35, 255);
	SDL_RenderFillRect( ren, &background );
}
