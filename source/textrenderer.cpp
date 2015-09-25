#include "textrenderer.h"

TextRenderer::TextRenderer()
{
	// Initialize SDL_TTF to render Text
	ifont = NULL;

	if ( TTF_Init() < 0 )
	{
		std::cout<<"SDL_TTF was not initialized! SDL_ERROR: "<<TTF_GetError()<<std::endl;
	} else {
		ifont = TTF_OpenFont("img/font.ttf", 46);
		if ( ifont == NULL )
		{
			std::cout<<"Font could not be loaded! SDL_ERROR: "<<TTF_GetError()<<std::endl;
		}
	}
}

void TextRenderer::RenderText( SDL_Renderer* ren, const char* message, int posx, int posy )
{
	//Test Text
	SDL_Surface* surfacetext = TTF_RenderText_Shaded( ifont, message, White, BG);
	SDL_Texture* text = SDL_CreateTextureFromSurface( ren, surfacetext );

	SDL_Rect text_rect;
	text_rect.x = posx;
	text_rect.y = posy;
	text_rect.w = surfacetext->w;
	text_rect.h = surfacetext->h;

	SDL_RenderCopy( ren, text, NULL, &text_rect );

	SDL_FreeSurface( surfacetext );
}

TextRenderer::~TextRenderer()
{
	TTF_CloseFont(ifont);
	ifont = NULL;
}
