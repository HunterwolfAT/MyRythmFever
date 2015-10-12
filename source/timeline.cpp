#include "timeline.h"


void Timeline::Init( int screenHeight, TextRenderer* textren, AudioPlayer* audiopl )
{
	width = 1280;
	height = 100;
	marker = 0;
	offset = 130;
	zoomlvl = 0;

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

	// Render Test Text
	//textrenderer->RenderText( ren, "This is my new test text.", 80, window.y + 5);
	testy->Render( ren );
}

void Timeline::Update( int newMarkerPos )
{
    if ( audioplayer->IsPlaying() )
    {
        marker += 1;
    }
}
