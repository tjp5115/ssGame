#ifndef SSLOOP_H 
#define SSLOOP_H 
#include "stdafx.h"
#include "SDL_Setup.h"
#include "GlobalState.h"
#include "Environment.h"
#include "MainCharacter.h"
class ssLoop
{
public:
	ssLoop(int p_width,int p_height);
	~ssLoop();

	void loop();

private:
	Environment *stage;

	SDL_Setup *setup;
	GlobalState *gs;

	MainCharacter *character;
};
#endif
