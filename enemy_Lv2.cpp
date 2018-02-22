#include "enemy_Lv2.h"

void EnemyLv2::init(string* arr, int enemyCnt)
{
	initFlag = false;

	if (enemyCnt > -1 && enemyCnt < 2)
	{
		x = XMAX - 2;
		y = YMIN;
	}
	else if (enemyCnt == 2)
	{
		x = XMIN;
		y = YMAX - 1;
	}
	else if (enemyCnt == 3)
	{
		x = XMAX - 2;
		y = YMAX - 1;
	}

	moveTo(arr);
}

Point EnemyLv2::moveTo(string* arr)
{
	if (!initFlag)
	{
		arr[y].replace(x, 2, enemy);
		initFlag = true;
	}
	else
	{

		int direction = (rand() % 8) + 1;

		if (direction == 1) // Left
		{
			x -= 2;
			if (x < XMIN)
				x += 2;
			else
			{
				arr[y].replace(x + 2, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 2) // Right
		{
			x += 2;
			if (x > XMAX - 1)
				x -= 2;
			else
			{
				arr[y].replace(x - 2, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 3) // Up
		{
			y--;
			if (y < YMIN)
				y++;
			else
			{
				arr[y + 1].replace(x, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 4) // Down
		{
			y++;
			if (y > YMAX - 1)
				y--;
			else
			{
				arr[y - 1].replace(x, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 5) // Left & Up
		{
			x -= 2;
			y--;

			if (x < XMIN || y < YMIN)
			{
				x += 2;
				y++;
			}
			else
			{
				arr[y + 1].replace(x + 2, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 6) // Right & Up
		{
			x += 2;
			y--;

			if (x > XMAX - 1 || y < YMIN)
			{
				x -= 2;
				y++;
			}
			else
			{
				arr[y + 1].replace(x - 2, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 7) // Left & Down
		{
			x -= 2;
			y++;

			if (x < XMIN || y > YMAX - 1)
			{
				x += 2;
				y--;
			}
			else
			{
				arr[y - 1].replace(x + 2, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 8) // Right & Down
		{
			x += 2;
			y++;

			if (x > XMAX - 1 || y > YMAX - 1)
			{
				x -= 2;
				y--;
			}
			else
			{
				arr[y - 1].replace(x - 2, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
	}

	Point p;
	p.setXY(x, y);
	return p;
}