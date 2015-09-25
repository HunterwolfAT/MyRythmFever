#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "timeline.h"

class Interface{

	private:
		Timeline timeline;

		TTF_Font *ifont;	// Interface

	public:
		Interface( int windowheight );
		~Interface();
		void Render( SDL_Renderer* ren );
};

#endif
