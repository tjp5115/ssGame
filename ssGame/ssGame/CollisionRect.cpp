#include "CollisionRect.h"


CollisionRect::CollisionRect(Point *point_p, int w, int h)
{
	radiusX = w;
	radiusY = h;
	
	cntr_pt = point_p;

}

CollisionRect::CollisionRect()
{
	radiusX = 0.0;
	radiusY = 0.0;

	cntr_pt = new Point();

}
CollisionRect::~CollisionRect()
{
}

SDL_Rect CollisionRect::drawCollisionRect(){
	SDL_Rect temp;
	temp.h = radiusY * 2;
	temp.w = radiusX * 2;
	temp.x = cntr_pt->x - radiusX;
	temp.y = cntr_pt->y - radiusY;
	return temp;
}