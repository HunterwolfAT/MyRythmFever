#include "interface.h"

Interface::Interface( int windowheight )
{
	textren = new TextRenderer();

	// Initialize Interface Components
	timeline.Init( windowheight, textren );

}

void Interface::Render( SDL_Renderer* ren )
{
	timeline.Render( ren );
}

Interface::~Interface()
{
}
