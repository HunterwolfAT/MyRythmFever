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

void TextRenderer::RenderText( const char* message, int posx, int posy )
{

}

TextRenderer::~TextRenderer()
{
	TTF_CloseFont(ifont);
	ifont = NULL;
}
