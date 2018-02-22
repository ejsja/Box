#pragma once
#include "enemy.h"
#include "point.h"

class EnemyLv3 : public Enemy {
	bool initFlag;
	int x, y;
public:
	void init(string*, int);
	Point moveTo(string*);
};
