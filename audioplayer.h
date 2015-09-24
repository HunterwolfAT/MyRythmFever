#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <SDL2/SDL_mixer.h>
#include <iostream>

class AudioPlayer
{
	private:
		int result;
		int flags;

		Mix_Music *song;

	public:
		AudioPlayer();
		~AudioPlayer();
		void LoadSong( const char* songtitle );
		void PlaySong();
		void PauseSong();
		void SetSongPosition( double songpos );
};

#endif
