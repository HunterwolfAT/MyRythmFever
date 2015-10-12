#include "timeline.h"


void Timeline::Init( int screenHeight, TextRenderer* textren, AudioPlayer* audiopl )
{
	width = 1280;
	height = 100;
	marker = 0.0;
	offset = 130;
	zoomlvl = 100;      // Number of pixels for one Minute. Increase to zoom in, decrease to zoom out.
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

void Timeline::Render( SDL_Renderer *ren )
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
        for (int i = 0; i < 20; i++)
        {
            SDL_RenderDrawLine( ren, offset + ( i * audioplayer->GetBPM() ), window.y + 40, offset + ( i * audioplayer->GetBPM() ), window.y + 60 );
        }
    }

	// Render Test Text
	//textrenderer->RenderText( ren, "This is my new test text.", 80, window.y + 5);
	testy->Render( ren );
}

void Timeline::Update( /*int newMarkerPos*/ )
{
    if ( audioplayer->IsPlaying() && !audioplayer->IsPaused()  )
    {
        currentTime = SDL_GetTicks();
        if ( startPlaying )
        {
            // This is really bad and will definitly cause desyncs
            lastTime = currentTime;
            startPlaying = false;
        }
        unsigned int deltaTime = currentTime - lastTime;
        double pixelpersecond = ( ( ( deltaTime / 1000.0 ) * 60.0 ) / 60);
        marker += pixelpersecond * ( zoomlvl / 60 );
        std::cout<<( ( deltaTime / 1000.0  ) * 60.0 )<<std::endl;
        lastTime = currentTime;
    }
    else {
         startPlaying = true;
    }
}
