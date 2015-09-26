#include "audioplayer.h"

AudioPlayer::AudioPlayer()
{
	result = 0;
	flags = MIX_INIT_MP3|MIX_INIT_FLAC|MIX_INIT_OGG;
	song = NULL;

	if ( flags != ( result = Mix_Init( flags ) ) )
	{
		std::cout<<"Could not initialize Mixer (result: "<<result<<")"<<std::endl<<Mix_GetError()<<std::endl;
	}

	// We dont use samples, so deallocate the default 8 channels...
	Mix_AllocateChannels(0);

	std::cout<<"SDL_Mixer Init successful!"<<std::endl;
}

void AudioPlayer::LoadSong( const char* songtitle )
{
	if ( Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640) )
	{
		std::cout<<"Couldn't open Audio Channel! SDL_Error: "<<Mix_GetError()<<std::endl;
	}
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
	Mix_PauseMusic();
}

void AudioPlayer::SetSongPosition( double songpos )
{
	if( Mix_SetMusicPosition( songpos ) )
	{
		std::cout<<"Could not set Song Position! SDL_Error: "<<Mix_GetError()<<std::endl;
	}
}

AudioPlayer::~AudioPlayer()
{
	Mix_FreeMusic( song );
}
