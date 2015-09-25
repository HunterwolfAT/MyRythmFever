#include "timeline.h"
#include <iostream>


void Timeline::Init( int screenHeight, TTF_Font *ifont ) 
{
	width = 1280;
	height = 100;
	marker = 0;
	offset = 130;

	window.w = width;
	window.h = height;
	window.x = 0;
	window.y = screenHeight - height;

	font = ifont;
}

void Timeline::Render( SDL_Renderer *ren )
{
	// Background
	SDL_SetRenderDrawColor( ren, 210, 60, 35, 255);
	SDL_RenderFillRect( ren, &window );

	// Marker
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 255);
	SDL_RenderDrawLine( ren, marker + offset, window.y + 20, marker + offset, window.y + 80 );

	//Test Text
	SDL_Color White = {255, 255, 255};
	SDL_Surface* surfacetext = TTF_RenderText_Blended( font, "This is a testing text.", White);
	SDL_Texture* text = SDL_CreateTextureFromSurface( ren, surfacetext );

	SDL_Rect text_rect;
	text_rect.x = 20;
	text_rect.y = window.y + 20;
	text_rect.w = 500;
	text_rect.h = 100;

	SDL_RenderCopy( ren, text, NULL, &text_rect );
}

void Timeline::Update( int newMarkerPos )
{
	marker = newMarkerPos;
}
