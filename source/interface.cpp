#include "interface.h"

Interface::Interface( GlobalProperties* glprop, AudioPlayer* audioplayer )
{
	textren = new TextRenderer();

	// Initialize Interface Components
	timeline.Init( textren, audioplayer, glprop );

}

void Interface::Render( SDL_Renderer* ren )
{
	timeline.Render( ren, textren );
}

void Interface::Update(  )
{
    timeline.Update();
}

Interface::~Interface()
{
}
