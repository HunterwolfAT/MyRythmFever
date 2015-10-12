#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <SDL2/SDL_mixer.h>
#include <iostream>

class AudioPlayer
{
	private:
		int result;
		int flags;
		int bpm;

		Mix_Music *song;

		bool paused;
		bool playing;

	public:
		AudioPlayer();
		~AudioPlayer();
		void LoadSong( const char* songtitle );
		void PlaySong();
		void PauseSong();
		void PausePlaySong();
		void SetSongPosition( double songpos );

		int GetBPM();
};

#endif
