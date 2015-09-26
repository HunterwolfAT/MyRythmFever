#ifndef TIMELINE_H
#define TIMELINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "textrenderer.h"
#include "interface_label.h"

class Timeline
{
	private:
		int width;
		int height;
		int marker;	// The Position of the Marker, showing where you are in the song
		int offset;	// Marker offset from left screen border to 0

		SDL_Rect window;
		TextRenderer* textrenderer;
		I_Label* testy;

	public:
		void Render( SDL_Renderer *ren );
		void Init( int screenHeight, TextRenderer *textren );
		void Update( int newMarkerPos );
		//Timeline( int windowHeight );

};

#endif
