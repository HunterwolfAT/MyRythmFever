#include "timeline.h"

// Help convert int to strings
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void Timeline::Init( int screenHeight, TextRenderer* textren, AudioPlayer* audiopl )
{
	width = 1280;
	height = 100;
	marker = 0.0;
	offset = 130;
	zoomlvl = 300;      // Number of pixels for one Minute. Increase to zoom in, decrease to zoom out.
    lastTime = 0;

    startPlaying = true;    // Do we have to start playing?

	window.w = width;
	window.h = height;
	window.x = 0;
	window.y = screenHeight - height;

	testy = new I_Label( textren, 20, window.y + 15, /* audiopl->GetBPM() */ "Testing" );
	textrenderer = textren;
	audioplayer = audiopl;
}

void Timeline::Render( SDL_Renderer *ren , TextRenderer* textren )
{
	// Background
	SDL_SetRenderDrawColor( ren, 210, 60, 35, 255);
	SDL_RenderFillRect( ren, &window );

	// Marker
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 255);
	SDL_RenderDrawLine( ren, marker + offset, window.y + 20, marker + offset, window.y + 80 );

    // Beats
    if ( audioplayer->GetBPM() != 0 )
    {
        int buffer = offset;
        while ( buffer < window.w )
        {
            for (int i = 0; i <= audioplayer->GetBPM(); i++ )
            {
                SDL_RenderDrawLine( ren, buffer + ( i * ( zoomlvl / audioplayer->GetBPM() ) ), window.y + 40, buffer + ( i * ( zoomlvl / audioplayer->GetBPM() ) ), window.y + 60 );
            }
            buffer += zoomlvl;
        }
    }

    // Timeline labels
    int buffer = offset;
    int counter = 0;
    std::string fullTime;

    I_Label* beat_label = new I_Label( textren, buffer, window.y + 5, "0" );
    beat_label->Render( ren );

    while ( buffer < window.w ) {
        fullTime = SSTR( counter ) + ":30";
        beat_label = new I_Label( textren, buffer + ( zoomlvl / 2 ), window.y + 5, fullTime.c_str() );
        beat_label->Render( ren );
        fullTime = SSTR( counter ) + ":15";
        beat_label = new I_Label( textren, buffer + ( zoomlvl / 4 ), window.y + 5, fullTime.c_str() );
        beat_label->Render( ren );
        fullTime = SSTR( counter ) + ":45";
        beat_label = new I_Label( textren, buffer + ( zoomlvl / 2 ) + ( zoomlvl / 4 ), window.y + 5, fullTime.c_str() );
        beat_label->Render( ren );

        counter++;

        fullTime = SSTR( counter ) + ":00";
        beat_label = new I_Label( textren, buffer + zoomlvl, window.y + 5, fullTime.c_str() );
        beat_label->Render( ren );

        buffer += zoomlvl;
    }


	// Render Test Text
	//textrenderer->RenderText( ren, "This is my new test text.", 80, window.y + 5);
	testy->Render( ren );
}

void Timeline::Update( /*int newMarkerPos*/ )
{
    marker = audioplayer->GetSongPosition() * ( zoomlvl / 60.0 );
}
