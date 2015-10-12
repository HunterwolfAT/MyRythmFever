#include "interface.h"

Interface::Interface( int windowheight, AudioPlayer* audioplayer )
{
	textren = new TextRenderer();

	// Initialize Interface Components
	timeline.Init( windowheight, textren, audioplayer );

}

void Interface::Render( SDL_Renderer* ren )
{
	timeline.Render( ren );
}

void Interface::Update(  )
{
    timeline.Update();
}

Interface::~Interface()
{
}
