#include "enemy_Lv3.h"

void EnemyLv3::init(string* arr, int enemyCnt)
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

Point EnemyLv3::moveTo(string* arr)
{
	if (!initFlag)
	{
		arr[y].replace(x, 2, enemy);
		initFlag = true;
	}
	else
	{

		int direction = (rand() % 8) + 1;
		int distance = (rand() % 2) + 1;
		
		if (direction == 1) // Left
		{
			x -= 2 * distance;
			if (x < XMIN)
				x += 2 * distance;
			else
			{
				arr[y].replace(x + 2 * distance, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 2) // Right
		{
			x += 2 * distance;
			if (x > XMAX - 1)
				x -= 2 * distance;
			else
			{
				arr[y].replace(x - 2 * distance, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 3) // Up
		{
			y -= distance;
			if (y < YMIN)
				y += distance;
			else
			{
				arr[y + distance].replace(x, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 4) // Down
		{
			y += distance;
			if (y > YMAX - 1)
				y -= distance;
			else
			{
				arr[y - distance].replace(x, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 5) // Left & Up
		{
			x -= 2 * distance;
			y -= distance;

			if (x < XMIN || y < YMIN)
			{
				x += 2 * distance;
				y += distance;
			}
			else
			{
				arr[y + distance].replace(x + 2 * distance, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 6) // Right & Up
		{
			x += 2 * distance;
			y -= distance;

			if (x > XMAX - 1 || y < YMIN)
			{
				x -= 2 * distance;
				y += distance;
			}
			else
			{
				arr[y + distance].replace(x - 2 * distance, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 7) // Left & Down
		{
			x -= 2 * distance;
			y += distance;

			if (x < XMIN || y > YMAX - 1)
			{
				x += 2 * distance;
				y -= distance;
			}
			else
			{
				arr[y - distance].replace(x + 2 * distance, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
		else if (direction == 8) // Right & Down
		{
			x += 2 * distance;
			y += distance;

			if (x > XMAX - 1 || y > YMAX - 1)
			{
				x -= 2 * distance;
				y -= distance;
			}
			else
			{
				arr[y - distance].replace(x - 2 * distance, 2, box);
				arr[y].replace(x, 2, enemy);
			}
		}
	}

	Point p;
	p.setXY(x, y);
	return p;
}