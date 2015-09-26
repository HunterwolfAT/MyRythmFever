#include "interface_label.h"

I_Label::I_Label( int x, int y, const char* text )
{
	posx = x;
	posy = y;
	value = text;
}

void I_Label::Render( SDL_Renderer* ren )
{
	if ( value != NULL )
	{
		textren.RenderText( ren, value, posx, posy );
	} else {
		std::cout<<"Cant render label... value is not set!"<<std::endl;
	}
}

I_Label::~I_Label()
{
}