#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "point.h"

#define XMIN 0
#define XMAX 20

#define YMIN 0
#define YMAX 10

using namespace std;

class Map {
	string arr[10];
public:
	Map();	
	string* getMap();
	void printMap() const;
	
};