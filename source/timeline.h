#ifndef TIMELINE_H
#define TIMELINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>

#include "textrenderer.h"
#include "audioplayer.h"
#include "interface_label.h"
#include "globalproperties.h"
class Timeline
{
	private:
		int width;
		int height;
        	double marker;	// The Position of the Marker, showing where you are in the song
		int offset;	// Marker offset from left screen border to 0
		int zoomlvl;	// show whole song or bits of it

        unsigned int lastTime, currentTime;
        bool startPlaying;


		SDL_Rect window;
		GlobalProperties* globalproperties;
		TextRenderer* textrenderer;
		AudioPlayer* audioplayer;
		I_Label* testy;


	public:
		void Render( SDL_Renderer *ren, TextRenderer* textren );
		void Init( TextRenderer *textren, AudioPlayer *audiopl, GlobalProperties *glprop );
		void Update( /*int newMarkerPos*/ );
		//Timeline( int windowHeight );

};

#endif
