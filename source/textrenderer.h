#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <SDL2/SDL_ttf.h>
#include <iostream>

class TextRenderer {

	public:
		TTF_Font *ifont;

	public:
		TextRederer();
		~TextRenderer();

		void RenderText( const char* message, int posx, int posy );

};

#endif
