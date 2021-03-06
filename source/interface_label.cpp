#include "interface_label.h"

I_Label::I_Label( TextRenderer* textrenderer, int x, int y, const char* text )
{
	posx = x;
	posy = y;
	value = text;
	textren = textrenderer;
}

void I_Label::Render( SDL_Renderer* ren, GlobalProperties* globalproperties )
{
	if ( value != NULL )
	{
		textren->RenderText( ren, 
					value, 
					posx * globalproperties->screenscale_factor, 
					posy * globalproperties->screenscale_factor );
	} else {
		std::cout<<"Cant render label... value is not set!"<<std::endl;
	}
}

I_Label::~I_Label()
{
}
