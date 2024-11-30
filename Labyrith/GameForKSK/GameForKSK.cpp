#include <iostream>
#include <string>
#include "Windows.h"
#include <conio.h>
#include <random>
#include <time.h>
using namespace std;
const int mapSizeX = 20;
const int mapSizeY = 10;
char map[mapSizeY][mapSizeX] = {
	{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
	{'X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X',' ',' ',' ',' ',' ','X','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

int playerY = 5;
class Enemy {
public:
	string name;
	int health;
	int hit;
	char sprite;
	int x;
	int y;
	Enemy() {
		name = "player";
		srand(time(0));
		health = 1 + rand() % 5;
		hit = 1;
		sprite = 'E';
		x = 2;
		y = 2;
	}
	char getSprite() {
		return sprite;
	}
	void changeSprite() {
		sprite = ' ';
	}
};
class Player {
public:
	string name;
	int health;
	int hit;
	char sprite;
	int x;
	int y;

	Player() {
		name = "player";
		srand(time(0));
		health = 10;
		hit = 1;
		sprite = 'P';
		x = 5;
		y = 5;
	}
};


bool isColliding(int x1, int y1, int x2, int y2) {
	return x1 == x2 && y1 == y2;
}

void battle(Player* player, Enemy* enemy) {
	while (player->health > 0 && enemy->health > 0) {

		enemy->health -= player->hit;
		player->health -= enemy->hit;
		cout << enemy->health << " " << player->health;
		cout << "Ваш ход. Вы нанесли " << player->hit << " урона." << endl;
		cout << "Ход врага. Вам нанесли " << enemy->hit << " урона." << endl;
		Sleep(500);
	}
	if (enemy->health == 0)
	{
		cout << "Вы победили!";
		cout << "Осталось здоровья " << player->health;
		enemy->sprite = ' ';
		getch();
	}
	else
	{
		cout << "Вы проиграли!";
		player->sprite = ' ';
		getch();
	}
	
}


void drawMap(Player* player, Enemy* enemy) {
	system("cls");
	for (int y = 0; y < mapSizeY; y++) {
		for (int x = 0; x < mapSizeX; x++) {
			if (y == player->y && x == player->x)
			{
				cout << player->sprite;
			}
			else if (y == enemy->y && x == enemy->x)
			{
				cout << enemy->getSprite();
			}
			else {
				cout << map[y][x];
			}
		}
		cout << endl;
	}
	
}

void movePlayer(char direction, Player* player) {
	switch (direction) {
	case 'w':
		if (player->y > 0 && map[player->y - 1][player->x] != 'X') {
			player->y--;
		}
		break;
		// ... аналогично для других направлений
	
	case 's':
		if (player->y < mapSizeY - 1 && map[player->y + 1][player->x] != 'X') {
			player->y++;
		}
		break;
	case 'a':
		if (player->x > 0 && map[player->y][player->x - 1] != 'X') {
			player->x--;
		}
		break;
	case 'd':
		if (player->x < mapSizeX - 1 && map[player->y][player->x + 1] != 'X') {
			player->x++;
		}
		break;
	}
}


int main()
{
	setlocale(LC_ALL, ".1251");
	Player p{};
	Enemy enemy{};
	char kill;
	while (true) {
		drawMap(&p, &enemy);
		char input = getch();
		movePlayer(input, &p);
		
		if (isColliding(p.x, p.y, enemy.x, enemy.y)) {
			battle(&p, &enemy);
			
		}
	}
	setlocale(LC_ALL, "");
	
	cout << " A A"<<endl;
	cout << "(o.o)" << endl;
	cout <<" > < ";
}
