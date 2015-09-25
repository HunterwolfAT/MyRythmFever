#ifndef NUMBERFIELD_H
#define NUMBERFIELD_H

#include <SDL2/SDL.h>
#include <iostream>

class I_Numberfield
{
	private:
		int posx, posy;
		int value;

	public:
		I_Numberfield( int x, int y );
		~I_Numberfield();

		void Render( SDL_Renderer* ren );
		void CheckClicked( int mousex, int mousey );
};

#endif
