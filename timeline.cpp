#include "timeline.h"


Timeline::Timeline() 
{

}

void Timeline::Render( SDL_Surface *screen )
{
	SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 180, 65, 0));
}
