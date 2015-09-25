#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <iostream>

class I_Button
{
	private:
		int posx, posy;
		void (*function)();	// Point to the function that supposed to be called when
					// the button is clicked

	public:
		I_Button( int x, int y, void (*func)() );
		~I_Button();

		void Render( SDL_Renderer* ren );
		void CheckClicked( int mousex, int mousey );
};

#endif
