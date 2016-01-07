#ifndef LABEL_H
#define LABEL_H

#include <SDL2/SDL.h>
#include <iostream>

#include "textrenderer.h"
#include "globalproperties.h"

class I_Label
{
	private:
		int posx, posy;
		const char* value;

		TextRenderer *textren;	

	public:
		I_Label( TextRenderer* textrenderer, int x, int y, const char* text );
		~I_Label();

		void Render( SDL_Renderer* ren, GlobalProperties* globalproperties );
};

#endif
