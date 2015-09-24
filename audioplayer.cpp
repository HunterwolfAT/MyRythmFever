#include "audioplayer.h"

AudioPlayer::AudioPlayer()
{
	result = 0;
	flags = MIX_INIT_MP3;
	song = NULL;

	if ( flags != ( result = Mix_Init( flags ) ) )
	{
		std::cout<<"Could not initialize Mixer (result: "<<result<<")"<<std::endl<<Mix_GetError()<<std::endl;
	}
}

void AudioPlayer::LoadSong( const char* songtitle )
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	song = Mix_LoadMUS( songtitle );
	if ( song == NULL )
	{
		std::cout<<"Could not load song!"<<std::endl<<Mix_GetError()<<std::endl;
		return;
	}
	std::cout<<"Loaded Song successfully!"<<std::endl;
}

void AudioPlayer::PlaySong()
{
	Mix_PlayMusic( song, 1 );
}

void AudioPlayer::PauseSong()
{

}

void AudioPlayer::SetSongPosition( double songpos )
{

}

AudioPlayer::~AudioPlayer()
{
	Mix_FreeMusic( song );
}
