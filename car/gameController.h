#pragma once

#include <string>
#include <vector>
#include <map>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "Drawing.h"

/*
根菜单
	开始游戏
		继续游戏
		重新开始
		返回
	读取存档
	排行榜
	结束游戏
*/

class menuItem {
public:
	menuItem();
	menuItem(string name, menuItem* father = nullptr);
	string name="root";//根菜单
	vector<menuItem*> items;
	menuItem* father = nullptr;
};
class point {
private:
	unsigned int Row;
	unsigned int Colum;
public:
	point();
	void setpoint(unsigned int row, unsigned int colum);
	unsigned int getrow();
	unsigned int getcolum();
};

class Snake {
private:
	int health = 1;
	point snakepoint[3000];
	string head = "right";
	int lang = 1;
public:
	int getsnakerow(unsigned int i);
	int getsnakecolum(unsigned int i);
	void setsnake(unsigned int i, unsigned int row, unsigned int colum);
	void changehead(string head);
	int getlang();
	string gethead();
	void setlang();
};

class gameController {
private:
	Drawing* screen = nullptr;
	menuItem* root = nullptr;
	menuItem* currentPointer = nullptr;
	int hard = 50;
	point checkPoint;
public:
	Snake snake1;
	gameController();
	void drawMenu(bool t = true);
	void drawBackground();
	void drawsnake(int lang);
	void drawCursor(bool t = true);
	void snakemove();
	void upCursor();
	void downCursor();
	string Action();
	void  running();
	void initialize();
	void checkpoint();
	void drawcheekpoint( bool t = true);
	void score();
	void gamestart();
};