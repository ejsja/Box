#pragma once
#include "map.h"
#include "point.h"


using namespace std;

class Player{
	const string player = "��";
	const string box = "��";
public:	
	Player(string*);	
	Point moveTo(int, int, string*, int);	
};