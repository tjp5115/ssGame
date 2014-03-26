#ifndef SLDSETUP_H 
#define SLDSETUP_H
#include "stdafx.h"
#include "GlobalState.h"
class SDL_Setup
{
public:
	SDL_Setup(int screenWidth, int screenHeight);
	~SDL_Setup();
	GlobalState *gs;
	void begin();
	void end();

	GlobalState * getGlobalState(){ return gs; }

private:
	int screenWidth;
	int screenHeight;


	SDL_Window *window;
};
#endif
