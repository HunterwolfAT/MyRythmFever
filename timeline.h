#ifndef TIMELINE_H
#define TIMELINE_H

#include <SDL2/SDL.h>

class Timeline
{
	private:
		int width;
		int height;
		int marker;	// The Position of the Marker, showing where you are in the song
		int offset;	// Marker offset from left screen border to 0

		SDL_Rect window;
	public:
		void Render( SDL_Renderer *ren );
		void Init( int windowHeight );
		//Timeline( int windowHeight );

};

#endif
