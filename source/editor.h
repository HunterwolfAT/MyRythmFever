#ifndef EDITOR_H
#define EDITOR_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>

#include "audioplayer.h"
#include "interface.h"

class Editor {
	private:
		SDL_Renderer* ren;
		SDL_Window* window;
		SDL_Event event;
		int WINDOW_WIDTH;
		int WINDOW_HEIGHT;
		_Bool running;

		Interface *interface;
		AudioPlayer audioplayer;

		int init( const char* songfiletitle );
	public:
		void loop( const char* songfiletitle );
		Editor();
		~Editor();
};

#endif
