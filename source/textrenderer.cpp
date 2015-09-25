#include "textrenderer.h"

TextRenderer::TextRenderer()
{
	// Initialize SDL_TTF to render Text
	ifont = NULL;

	if ( TTF_Init() < 0 )
	{
		std::cout<<"SDL_TTF was not initialized! SDL_ERROR: "<<TTF_GetError()<<std::endl;
	} else {
		ifont = TTF_OpenFont("img/font.ttf", 116);
		if ( ifont == NULL )
		{
			std::cout<<"Font could not be loaded! SDL_ERROR: "<<TTF_GetError()<<std::endl;
		}
	}
}

void TextRenderer::RenderText( SDL_Renderer* ren, const char* message, int posx, int posy )
{
	//Test Text
	SDL_Color White = {255, 255, 255};
	SDL_Surface* surfacetext = TTF_RenderText_Blended( ifont, message, White);
	SDL_Texture* text = SDL_CreateTextureFromSurface( ren, surfacetext );

	SDL_Rect text_rect;
	text_rect.x = posx;
	text_rect.y = posy;
	text_rect.w = 500;
	text_rect.h = 100;

	SDL_RenderCopy( ren, text, NULL, &text_rect );
}

TextRenderer::~TextRenderer()
{
	TTF_CloseFont(ifont);
	ifont = NULL;
}
