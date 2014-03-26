#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "stdafx.h"
#include "Sprite.h"
#include <vector>
class Environment
{
public:
	Environment(GlobalState *p_gs);
	~Environment();

	void draw();

	void update();

private:
	std::vector<Sprite*> land;
	Sprite* bg;
	int playerStartPos;
	GlobalState *gs;
};
#endif
