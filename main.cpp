#include "main.h"
#include "map.h"
#include "player.h"
#include "enemy_Lv1.h"
#include "enemy_Lv2.h"
#include "enemy_Lv3.h"

int main()
{
	srand((unsigned)time(NULL));
	
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords = { 0, 0 };

	char key;
	bool keyFlag = false;
	bool continueFlag = true;
	int x = 0, y = 0;
	int enemyLevel, enemyCount;

	Map m;
	Player p(m.getMap());
	Enemy** e;
	Point playerPoint;
	Point* enemyPoint;
	

	while (1)
	{
		cout << "난이도를 입력하시오 (1 ~ 3, 미 입력 시 1 로 설정 됩니다.) : ";
		enemyLevel = getchar();
		
		if (enemyLevel == '\n')
		{
			enemyLevel = 1;
			break;
		}
		else if (enemyLevel > '3' || enemyLevel < '1')
		{
			cout << "잘못된 입력입니다." << endl;
			while(getchar() != '\n');
			continue;
		}
		else
		{
			enemyLevel -= '0';
			while (getchar() != '\n');
			break;
		}
	}	

	while (1)
	{
		cout << "적의 수를 입력하시오 (1 ~ 3, 미 입력 시 1 로 설정 됩니다.) : ";
		enemyCount = getchar();		

		if (enemyCount == '\n')
		{
			enemyCount = 1;
			break;
		}
		else if (enemyCount > '3' || enemyCount < '1')
		{
			cout << "잘못된 입력입니다." << endl;
			while (getchar() != '\n');
			continue;
		}
		else
		{
			enemyCount -= '0';
			while (getchar() != '\n');
			break;
		}
	}
	
	e = new Enemy*[enemyCount];
	enemyPoint = new Point[enemyCount];
	
	if (enemyLevel == 1)
	{
		for (int i = 0; i < enemyCount; i++)
		{
			e[i] = new EnemyLv1;
			e[i]->init(m.getMap(), i + 1);
		}
	}
	else if (enemyLevel == 2)
	{
		for (int i = 0; i < enemyCount; i++)
		{
			e[i] = new EnemyLv2;
			e[i]->init(m.getMap(), i + 1);
		}
	}
	else if (enemyLevel == 3)
	{
		for (int i = 0; i < enemyCount; i++)
		{
			e[i] = new EnemyLv3;
			e[i]->init(m.getMap(), i + 1);
		}
	}
	
	system("cls");
	system("mode con: lines=35 cols=85");
	SetConsoleCursorPosition(consoleHandler, coords);
	m.printMap();
	
	while (continueFlag)
	{
		key = _getch();

		if (key == '0')
			break;

		if (key == LEFT)
		{
			x -= 2;
			if (x < XMIN)
			{
				cout << "이동할 수 없는 지역입니다." << endl;
				x += 2;
			}
			else
			{
				cout << "                          " << endl;
				playerPoint = p.moveTo(x, y, m.getMap(), 1);				
			}
			keyFlag = true;
		}
		else if (key == RIGHT)
		{
			x += 2;
			if (x > XMAX - 1)
			{
				cout << "이동할 수 없는 지역입니다." << endl;
				x -= 2;
			}
			else
			{
				cout << "                          " << endl;
				playerPoint = p.moveTo(x, y, m.getMap(), 2);
			}
			keyFlag = true;
		}
		else if (key == UP)
		{
			y--;
			if (y < YMIN)
			{
				cout << "이동할 수 없는 지역입니다." << endl;
				y++;
			}
			else
			{
				cout << "                          " << endl;
				playerPoint = p.moveTo(x, y, m.getMap(), 3);
			}
			keyFlag = true;
		}
		else if (key == DOWN)
		{
			y++;
			if (y > YMAX - 1)
			{
				cout << "이동할 수 없는 지역입니다." << endl;
				y--;
			}
			else
			{
				cout << "                          " << endl;
				playerPoint = p.moveTo(x, y, m.getMap(), 4);
			}
			keyFlag = true;
		}
	
		if (keyFlag == true)
		{
			for(int i = 0; i < enemyCount; i++)
				enemyPoint[i] = e[i]->moveTo(m.getMap());
	
			keyFlag = false;
			
			
			SetConsoleCursorPosition(consoleHandler, coords);
			m.printMap();
			
			for (int i = 0; i < enemyCount; i++)
			{
				if (playerPoint == enemyPoint[i])
				{
					cout << "GAME OVER . . ." << endl << endl;
					continueFlag = false;
				}				
			}

			Point temp(XMAX - 2, YMAX - 1);

			if (playerPoint == temp)
			{
				cout << "목적지에 도달하였습니다 . . . ! !" << endl << endl;
				continueFlag = false;
			}
			
			cout << flush;
		}		
	}

	delete *e;
	delete[] e;
	delete[] enemyPoint;

	return 0;
}