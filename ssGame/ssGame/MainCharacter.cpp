#include "MainCharacter.h"


MainCharacter::MainCharacter(GlobalState *p_gs)
{

	gs = p_gs;
	character = NULL;
	character = new Sprite(gs, "data/character/p1_spritesheet.png", gs->getScreenWidth() / 2, gs->playerStartPos, 72, 97, CollisionRect());

	animationRow = 5;

	character->setupAnimation(7, 6);
	character->playAnimation(1, 1, 2, animationRow);

	ticks = SDL_GetTicks();
	debugTime = SDL_GetTicks();

	move_forward, move_back,onGround = false;

	speed = 10;
	
	velocityX = 4.0;// not used as the jump update. should be instead of the current.
	velocityY = 0.0; 
	gravity = -0.5;
}


MainCharacter::~MainCharacter()
{
	delete character;
}

void MainCharacter::draw(){
	character->drawSteady();
}

void MainCharacter::update(){
	updateMovement();
	updateAnimation();
}

void MainCharacter::updateMovement(){
	SDL_Event *k = gs->getMainEvent();

	if (ticks + speed < SDL_GetTicks()){
		if (move_forward){
			gs->cameraX -= 5; //need to change static
		}
		if (move_back){
			gs->cameraX += 5; //need to change static
		}



		velocityY += gravity;
		gs->cameraY += velocityY;
		if (gs->cameraY < 0){ // need to change static
			gs->cameraY = 0;
			velocityY = 0.0;
			if (!onGround){
				character->playAnimation(1, 3, animationRow, 0);
			}

			onGround = true;
		}


		ticks = SDL_GetTicks();
	}
	if (k->type == SDL_KEYDOWN){
		keyDownEvents(k);
	}
	if (k->type == SDL_KEYUP){
		keyUpEvents(k);
	}

}
void MainCharacter::keyUpEvents(SDL_Event *k){
	SDL_Keycode key = k->key.keysym.sym;
	if (key == SDLK_d){
		move_forward = false;
	}
	if (key == SDLK_a ){
		move_back = false;
	}
	if (key == SDLK_SPACE){ 
		endJump();
	}
}

void MainCharacter::keyDownEvents(SDL_Event *k){
	SDL_Keycode key = k->key.keysym.sym;
	if (key == SDLK_a ){
		move_back = true;
	}
	if (key == SDLK_d ){
		move_forward = true; 
	}
	if (key == SDLK_SPACE){
		startJump();
	}
//	printf("velocityY: %d   velocityX: %d\n", velocityY, velocityX);

}
void MainCharacter::updateAnimation(){

	if (move_forward){
		animationRow = 1;
		animateMove();
	}
	else if (move_back){
		animationRow = 4;
		animateMove();
	}
	else {
		animateStill();
	}
}

void MainCharacter::startJump(){
	if (onGround){
		velocityY = 18.0;
		onGround = false;
	}
}

void MainCharacter::endJump(){
	if (velocityY > 9.0){
		velocityY = 9.0;
	}
}

void MainCharacter::animateStill(){
	
	if (!onGround){
		character->playAnimation(5, 5, animationRow, 0);
	}
	else{
		character->playAnimation(0, 0, 2, 100);
	}
	
}


void MainCharacter::animateMove(){
	if (!onGround){
		character->playAnimation(5, 5, animationRow, 0);
	}
	else{
		character->playAnimation(1, 3, animationRow, 250);
	}
}
