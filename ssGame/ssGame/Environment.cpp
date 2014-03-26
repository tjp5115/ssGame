#include "Environment.h"
Environment::Environment(GlobalState *p_gs)
{
	gs = p_gs;
	
	bg = NULL;
	bg = new Sprite(gs, "data/environment/iceStage/bg.png", 0, 0, gs->getScreenWidth(), gs->getScreenHeight()*2, CollisionRect());
	int y = gs->getScreenHeight() / 2;
	int h = 90;
	int w = 170;
	for (int x = 0; x < 100; ++x){
		if (x % 2 == 0){
			land.push_back(new Sprite(gs, "data/environment/iceStage/tundra.png", x * 90, y + 90, w, h, CollisionRect( )));
		}
		else{
			land.push_back(new Sprite(gs, "data/environment/iceStage/iceBlock.png", x * 90, y + 90, w, h, CollisionRect()));
		}
	}
	
	gs->playerStartPos = y ;
}


Environment::~Environment()
{
	for (int i = 0; i < land.size(); i++){
		delete land[i];
	}
	land.clear();
	delete bg;
}

void Environment::draw(){
	bg->drawSteady();
	for (int i = 0; i < land.size(); ++i){
		land[i]->draw();
	}
}

void Environment::update(){

}
