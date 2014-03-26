#ifndef GLOBALSTATE_H
#define GLOBALSTATE_H
#include "stdafx.h"

class GlobalState
{
public:
	GlobalState(int p_height, int p_width,SDL_Window *p_window);
	~GlobalState();

	void setWidth(int w){ screen_width = w; }
	void setHeight(int h){ screen_height = h; }
	void setCamera(float x, float y){ cameraX = x; cameraY= y; }
	void setCameraX(float x){ cameraX = x; }
	void setCameraY(float y){ cameraY = y; }
	void setMouseState();
	
	void quitGame(){ quit = true; }
	
	int getMouseX(){ return mouseX; }
	int getMouseY(){ return mouseY; }

	int getScreenWidth(){ return screen_width; }
	int getScreenHeight(){ return screen_height; }

	bool getQuit(){ return quit; }

	SDL_Renderer* getRenderer(){ return renderer; }
	SDL_Event* getMainEvent(){ return event; }

	bool isCharacterColliding();


	float cameraX;
	float cameraY;

	int playerStartPos;
private:
	int screen_width;
	int screen_height;

	int mouseX;
	int mouseY;


	bool quit;

	SDL_Renderer *renderer;
	SDL_Event *event;

};
#endif
