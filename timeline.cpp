#include "timeline.h"
#include <iostream>


void Timeline::Init( int windowHeight ) 
{
	width = 1280;
	height = 100;
	marker = 0;
	offset = 130;

	background.w = width;
	background.h = height;
	background.x = 0;
	background.y = windowHeight - height;
	std::cout<<offset<<std::endl;
}

void Timeline::Render( SDL_Renderer *ren )
{
	// Background
	SDL_SetRenderDrawColor( ren, 210, 60, 35, 255);
	SDL_RenderFillRect( ren, &background );

	// Marker
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 255);
	SDL_RenderDrawLine( ren, marker + offset, background.y + 20, marker + offset, background.y + 80 );
}
