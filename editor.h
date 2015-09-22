#include <SDL2/SDL.h>
#include <stdbool.h>

#ifndef EDITOR_H
#define EDITOR_H

class Editor {
	private: 
		SDL_Surface* screenSurface;
		SDL_Window* window;
		SDL_Event event;
		int WINDOW_WIDTH;
		int WINDOW_HEIGHT;
		_Bool running;

		int init();
	public:
		void test();
		void loop();
		Editor();
};

#endif
