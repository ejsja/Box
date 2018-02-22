#include "player.h"

Player::Player(string* arr)
{
	moveTo(XMIN, YMIN, arr, 0);
}

Point Player::moveTo(int x, int y, string* arr, int key)
{
	if(key == 0)
		arr[y].replace(x, 2, player);
	else if (key == 1) // left
	{
		arr[y].replace(x + 2, 2, box);
		arr[y].replace(x, 2, player);
	}
	else if (key == 2) // right
	{
		arr[y].replace(x - 2, 2, box);
		arr[y].replace(x, 2, player);
	}
	else if (key == 3) // up
	{
		arr[y + 1].replace(x, 2, box);
		arr[y].replace(x, 2, player);
	}
	else if (key == 4) // down
	{
		arr[y - 1].replace(x, 2, box);
		arr[y].replace(x, 2, player);
	}

	Point p;
	p.setXY(x, y);

	return p;
}