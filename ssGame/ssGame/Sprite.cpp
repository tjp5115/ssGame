#include "Sprite.h"


Sprite::Sprite(GlobalState *p_gs, const char* FilePath, int x, int y, int w, int h,CollisionRect p_collision)
{
	gs = p_gs;
	collisionRect = p_collision;
	image = NULL;
	collImg = NULL;
	image_height = h;
	image_width = w;
	image = IMG_LoadTexture(gs->getRenderer(), FilePath);

	collImg = IMG_LoadTexture(gs->getRenderer(), "data/debug/rect.png");

	if (image == NULL){
		std::cout << "Error loading image: " << FilePath << std::endl;
	}
	if (collImg == NULL){
		std::cout << "Error loading image: data/debug/rect.png" << std::endl;
	}
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &image_width, &image_height);

	xPos = x;
	yPos = y;

	crop.w = image_width;
	crop.h = image_height;

	origin_x -= rect.w / 2;
	origin_y -= rect.h - 10;

	amount_frame_x = 0;
	amount_frame_y = 0;

	camera.x = rect.x + gs->cameraX;
	camera.y = rect.y + gs->cameraY;
	camera.w = rect.w;
	camera.h = rect.h;

}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);
}

void Sprite::setupAnimation(int x, int y){
	amount_frame_x = x;
	amount_frame_y = y;
}

void Sprite::playAnimation(int beginFrame, int endFrame, int row, float speed){
	if (animationDelay + speed < SDL_GetTicks()){
		if (endFrame <= currentFrame){
			currentFrame = beginFrame;
		}
		else{
			currentFrame++;
		}
		crop.x = currentFrame * image_width / amount_frame_x;
		crop.y = image_height / amount_frame_y * row;
		crop.w = image_width / amount_frame_x;
		crop.h = image_height / amount_frame_y;

		animationDelay = SDL_GetTicks();
	}
}

void Sprite::drawSteady(){
	SDL_RenderCopy(gs->getRenderer(), image, &crop, &camera);
}

void Sprite::draw(void){
	camera.x = rect.x + gs->cameraX;
	camera.y = rect.y + gs->cameraY;
	SDL_Rect colRect = collisionRect.drawCollisionRect();


	SDL_RenderCopy(gs->getRenderer(), image, &crop, &camera);
	SDL_RenderCopy(gs->getRenderer(), collImg, NULL, &colRect);
}

float Sprite::getX(){
	return xPos;
}

float Sprite::getY(){
	return yPos;
}

void Sprite::setX(float x){
	rect.x = int(x + origin_x);
	xPos = x;
}
void Sprite::setY(float y){
	rect.y = int(y + origin_y);
	yPos = y;
}

void Sprite::setPosition(float x, float y){
	rect.x = (int)x;
	rect.y = (int)y;
	xPos = x;
	yPos = y;
}

float Sprite::getHeight(){
	return float(rect.h);
}
float Sprite::getWidth(){
	return float(rect.w);
}
void Sprite::setHeight(int h){
	rect.h = h;
}
void Sprite::setWidth(int w){
	rect.w = w;
}

bool Sprite::isColliding(CollisionRect r){
	/* OLD COLLUSION DETECTION
	
	return !(
		collisionRect.getRect().x + collisionRect.getRect().w < r.getRect().x ||
		collisionRect.getRect().y + collisionRect.getRect().h < r.getRect().y ||
		collisionRect.getRect().x > r.getRect().x + r.getRect().w ||
		collisionRect.getRect().y > r.getRect().y + r.getRect().h
		);
		*/
	return false;
}

