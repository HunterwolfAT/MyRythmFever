#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class TextRenderer {

	public:
		TTF_Font *ifont;	// Interface Font
		SDL_Color White = {255, 255, 255};
		SDL_Color BG = {190, 30, 35};

	public:
		TextRenderer();
		~TextRenderer();

		void RenderText( SDL_Renderer* ren, const char* message, int posx, int posy );

};

#endif
