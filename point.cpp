#include "point.h"
Point::Point() {};
Point::Point(int x, int y) : x(x), y(y){};

void Point::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Point::operator==(Point p)
{
	return (this->x == p.x) && (this->y == p.y) ? true : false;
}