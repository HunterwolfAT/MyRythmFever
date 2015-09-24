#include <SDL2/SDL.h>
#include <stdbool.h>

#include "timeline.h"
#include "audioplayer.h"

#ifndef EDITOR_H
#define EDITOR_H

class Editor {
	private: 
		SDL_Renderer* ren;
		SDL_Window* window;
		SDL_Event event;
		int WINDOW_WIDTH;
		int WINDOW_HEIGHT;
		_Bool running;

		Timeline timeline;
		AudioPlayer audioplayer;

		int init();
	public:
		void test();
		void loop();
		Editor();
};

#endif
