#ifndef TIMELINE_H
#define TIMELINE_H

#include <SDL2/SDL.h>

class Timeline
{
	private:
		int width;
		int height;
		int marker;

		SDL_Rect background;
	public:
		void Render( SDL_Renderer *ren );
		void Init( int windowHeight );
		//Timeline( int windowHeight );

};

#endif
