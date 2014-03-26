#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
#include "stdafx.h"
#include "Sprite.h"
#include "GlobalState.h"
#include "Environment.h"
class MainCharacter
{
public:
	MainCharacter(GlobalState *p_gs);
	~MainCharacter();

	void draw();

	void update();
	void setStage(Environment * p_env){ environment = p_env; }

private:
	GlobalState *gs;
	Sprite *character;

	void updateAnimation();
	void updateMovement();

	void keyDownEvents(SDL_Event *k);
	void keyUpEvents(SDL_Event *k);

	int debugTime;
	int ticks;

	int distance;
	
	int animationRow;

	void startJump();
	void endJump();

	bool move_forward, move_back;
	int speed;

	float velocityX;
	float velocityY;
	float gravity;
	bool onGround;
	Environment *environment;
	void animateMove();
	void animateStill();
};
#endif
