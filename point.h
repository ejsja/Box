#pragma once

class Point
{
	int x;
	int y;
public:
	Point();
	Point(int, int);
	void setXY(int, int);
	bool operator==(Point p);
};