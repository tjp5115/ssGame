#ifndef COLLISIONRECT_H 
#define COLLISIONRECT_H 
#include "stdafx.h"
class CollisionRect
{
public:
	CollisionRect(void);
	CollisionRect(Point *point_p, int w, int h);
	~CollisionRect();

	float radiusX;
	float radiusY;
	Point *cntr_pt;
	SDL_Rect collisionRect;

	SDL_Rect drawCollisionRect(); 

private:

};
#endif
