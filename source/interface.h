#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "timeline.h"
#include "textrenderer.h"

class Interface{

	private:
		Timeline timeline;
		TextRenderer *textren;

	public:
		Interface( int windowheight );
		~Interface();
		void Render( SDL_Renderer* ren );
};

#endif