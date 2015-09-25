#include "interface_button.h"

I_Button::I_Button( int x, int y, void (*func)() )
{
	posx = x;
	posy = y;
	function = func;
}

void I_Button::Render( SDL_Renderer* ren )
{

}

void I_Button::CheckClicked( int mousex, int mousey )
{

}

I_Button::~I_Button()
{
	function = NULL;
}
