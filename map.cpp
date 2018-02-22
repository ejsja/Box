#include "map.h"

Map::Map()
{	
	for (int i = 0; i < XMAX / 2; i++)
	{
		for (int j = 0; j < YMAX; j++)
			arr[i].replace(j * 2, 2, "бр");
	}
}

string* Map::getMap()
{
	return arr;
}

void Map::printMap() const
{
	for (int i = 0; i < XMAX / 2; i++)
	{
		for (int j = 0; j < YMAX; j++)
			cout << arr[i].substr(j * 2, 2) << '\t';
		cout << endl << endl << endl;
	}	
}
