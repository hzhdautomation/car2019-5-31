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

class event {
private:
	string state="menu";
public:
	void changestate(string st);
	string getstate();
};
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
	bool operator==(point& b);
	void setrow(unsigned int row);
	void setcolum(unsigned int colum);
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
	void addlang();
	void resetlang();
	void Health();
	int getHealth();
	void resethealth();
	point getpoint(int i);
};

class gameController {
private:
	Drawing* screen = nullptr;
	menuItem* root = nullptr;
	menuItem* currentPointer = nullptr;
	int hard = 150;
	point checkPoint;
	event event;
	Snake snake1;
public:
	gameController();
	void drawMenu(bool t = true);
	void drawBackground();
	void drawsnake(int lang);
	void drawCursor(bool t = true);
	void snakemove();
	void upCursor();
	void downCursor();
	string Action(string action="null",bool t=false);
	void  running();
	void initialize();
	void checkpoint();
	void drawcheekpoint( bool t = true);
	void score();
	void gamestart();
	void dead();
	point getsnakepoint(int i);
	point getcheckpoint();
	int getsnakelang();
	string getsnakehead();
	void changesnakehead(string t);
};
extern gameController gameCtrl;
extern int I;