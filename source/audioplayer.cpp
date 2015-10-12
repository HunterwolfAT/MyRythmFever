#include "audioplayer.h"

AudioPlayer::AudioPlayer()
{
	result = 0;
	flags = MIX_INIT_MP3|MIX_INIT_FLAC|MIX_INIT_OGG;
	song = NULL;
	playing = false;
	paused = true;

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
	if ( playing == false )
	{
		Mix_PlayMusic( song, 1 );
		playing = true;
	} else {
		Mix_ResumeMusic();
	}
	paused = false;
}

void AudioPlayer::PauseSong()
{
	Mix_PauseMusic();
	paused = true;
}

void AudioPlayer::SetSongPosition( double songpos )
{
	// songpos in seconds
	//  - from beginning in OGG
	//  - from current position in MP3. Doesnt go reverse, call Mix_RewindMusic() maybe.
	if( Mix_SetMusicPosition( songpos ) )
	{
		std::cout<<"Could not set Song Position! SDL_Error: "<<Mix_GetError()<<std::endl;
	}
}

void AudioPlayer::PausePlaySong()
{
	if ( song == NULL )
	{
		std::cout<<"Can't play a song that isnt loaded!"<<std::endl;
	} else {
		if ( paused )
		{
			PlaySong();
		}
		else {
			PauseSong();
		}
	}
}

double AudioPlayer::GetSongPosition() {
     return songposition;
}

bool AudioPlayer::IsPlaying() {
     return playing;
}

AudioPlayer::~AudioPlayer()
{
	Mix_FreeMusic( song );
}
