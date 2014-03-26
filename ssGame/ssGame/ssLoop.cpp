#include "ssLoop.h"


ssLoop::ssLoop(int p_width,int p_height)
{
	setup = NULL;
	setup = new SDL_Setup(p_width, p_height);
	
	gs = NULL;
	gs = setup->getGlobalState();

	stage = NULL;
	stage = new Environment(gs);

	character = NULL;
	character = new MainCharacter(gs);
	character->setStage(stage);
}


ssLoop::~ssLoop()
{
}

void ssLoop::loop(){

	

	while ( !gs->getQuit() && gs->getMainEvent()->type != SDL_QUIT){
		gs->setMouseState();

		setup->begin();
		
		stage->update();
		stage->draw();

		character->update();
		character->draw();

		setup->end();
	}
}