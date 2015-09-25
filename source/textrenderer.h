#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class TextRenderer {

	public:
		TTF_Font *ifont;	// Interface Font

	public:
		TextRenderer();
		~TextRenderer();

		void RenderText( SDL_Renderer* ren, const char* message, int posx, int posy );

};

#endif
