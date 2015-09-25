#ifndef ELEMENT_H
#define ELEMENT_H

class I_Element {

	private:
		int posx, posy;

	public:
		void Render( SDL_Renderer* ren );
		void CheckClicked( int mousex, int mousey );
};

#endif
