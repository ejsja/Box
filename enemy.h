#pragma once
#include "map.h"

using namespace std;

class Enemy{

protected:
	const string enemy = "б▌";
	const string box = "бр";

public:
	virtual void init(string*, int) = 0;
	virtual Point moveTo(string*) = 0;
};


	