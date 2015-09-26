#ifndef LABEL_H
#define LABEL_H

#include <SDL2/SDL.h>
#include <iostream>

#include "textrenderer.h"

class I_Label
{
	private:
		int posx, posy;
		const char* value;

		TextRenderer textren;	// This is pretty shitty cause now
					// the font gets loaded with every single label

	public:
		I_Label( int x, int y, const char* text );
		~I_Label();

		void Render( SDL_Renderer* ren );
};

#endif
