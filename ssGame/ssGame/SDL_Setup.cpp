#include "SDL_Setup.h"

SDL_Setup::SDL_Setup(int screenWidth, int screenHeight){
	SDL_Init(SDL_INIT_VIDEO);


	window = NULL;
	window = SDL_CreateWindow("Tyler's SS", 100, 100, screenWidth, screenHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	gs = NULL; 
	gs = new GlobalState(screenWidth, screenHeight, window);

	if (window == NULL){
		std::cout << "failed to create window" << std::endl;
	}

}


SDL_Setup::~SDL_Setup()
{
	delete gs;
	SDL_DestroyWindow(window);
}

void SDL_Setup::begin(){
	SDL_PollEvent(gs->getMainEvent());
	SDL_RenderClear(gs->getRenderer());
}

void SDL_Setup::end(){
	SDL_RenderPresent(gs->getRenderer());
}


