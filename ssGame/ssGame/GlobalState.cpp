#include "GlobalState.h"

GlobalState::GlobalState(int p_width, int p_height, SDL_Window *p_window)
{
	event = NULL;
	event = new SDL_Event();

	renderer = NULL;
	renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);

	mouseX = 0;
	mouseY = 0;
	
	screen_width = p_width;
	screen_height = p_height;

	cameraX = 0;
	cameraY = 0;

	quit = false;
	
}


GlobalState::~GlobalState()
{
	SDL_DestroyRenderer(renderer);
}

void GlobalState::setMouseState(){
	SDL_GetMouseState(&mouseX, &mouseY);
}

