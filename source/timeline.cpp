#include "timeline.h"
#include <iostream>


void Timeline::Init( int screenHeight ) 
{
	width = 1280;
	height = 100;
	marker = 0;
	offset = 130;

	window.w = width;
	window.h = height;
	window.x = 0;
	window.y = screenHeight - height;
}

void Timeline::Render( SDL_Renderer *ren )
{
	// Background
	SDL_SetRenderDrawColor( ren, 210, 60, 35, 255);
	SDL_RenderFillRect( ren, &window );

	// Marker
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 255);
	SDL_RenderDrawLine( ren, marker + offset, window.y + 20, marker + offset, window.y + 80 );
}

void Timeline::Update( int newMarkerPos )
{
	marker = newMarkerPos;
}
