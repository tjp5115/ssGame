#ifndef SPRITE_H
#define SPRITE_H
#include "stdafx.h"
#include "GlobalState.h"
#include "CollisionRect.h"
class Sprite
{
public:
	Sprite(GlobalState *p_gs, const char* FilePath, int x, int y, int w, int h, CollisionRect p_collision);
	~Sprite();

	void draw();
	
	float getX();
	float getY();
	
	void setX(float x);
	void setY(float y);

	void setPosition(float x, float y);

	void setOrigin(float x, float y);

	float getWidth();
	float getHeight();

	void setWidth(int w);
	void setHeight(int h);
	void playAnimation(int beginFrame, int endFrame, int row, float speed);
	void setupAnimation(int x, int y);

	CollisionRect getCollisionRext(){ return collisionRect; }

	void drawSteady();

	bool isColliding(CollisionRect theCollider);

	CollisionRect getCollisionRect(){ return collisionRect; }

	SDL_Rect getPositionRext(){ return rect; }
private:
	
	GlobalState *gs;

	CollisionRect collisionRect;

	float origin_x;
	float origin_y;
	float xPos;
	float yPos;

	int image_width;
	int image_height;

	int amount_frame_x;
	int amount_frame_y;

	int currentFrame;
	int animationDelay;
	SDL_Rect crop;
	SDL_Texture* image;
	SDL_Texture* collImg;

	SDL_Rect rect;

	SDL_Rect camera;
};
#endif
