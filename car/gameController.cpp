#include "gameController.h"
#include <fstream>


int row = 13;
int i = 0;
int i_running = 0;
int i_cursor = 0;
int i_snake = 1;
static int I = 1;

menuItem::menuItem(){
}

menuItem::menuItem(string name, menuItem* father) {
	this->name = name;
	this->father = father;
}

gameController::gameController() {
	screen = new Drawing;
	root = new menuItem("root");
	currentPointer = root;
	root->items.push_back(new menuItem("开始游戏", root));
	menuItem* temp = root->items[0];
	temp->items.push_back(new menuItem("继续游戏", temp));
	temp->items.push_back(new menuItem("重新开始", temp));
	temp->items.push_back(new menuItem("返回", temp));
	root->items.push_back(new menuItem("加载游戏", root));
	root->items.push_back(new menuItem("排行榜", root));
	root->items.push_back(new menuItem("退出游戏", root));
	//drawBackground();
}

void gameController::drawBackground(){
	char data[5000];
	std::fstream load;
	load.open("basepage.txt", ios::in);
	load.getline(data, 5000, '\r');
	image img;
	img.width = 120;
	img.height = 25;
	img.data = data;
	//cout << img.data << endl;
	screen->setImage(0, 0, 120, 25, img);
	screen->flushScreen();
}

void gameController::drawsnake(int lang)
{
	static int i;
	static int last_lang = 1;
	screen->setPixel(snake1.getsnakerow(I), snake1.getsnakecolum(I), true);
	screen->flushScreen();
	if (last_lang != lang)
	{
		last_lang = lang;
	}
	else {
		if (i_snake > lang)
		{
			screen->setPixel(snake1.getsnakerow((i_snake - lang) % 3000), snake1.getsnakecolum((i_snake - lang) % 3000), false);
			screen->flushScreen();
		}
	}
}

void gameController::drawCursor(bool t)
{
	if (t)
	{
    screen->setChar(row, 40, '>');
	screen->flushScreen();
	}
	else
	{
	screen->setChar(row, 40, ' ');
	screen->flushScreen();
	}	
}

void gameController::snakemove()
{
	static int i = 1;
	i = i++;
	static string last_key = "null";
	static int ROW = 20;
	static int COLUM = 20;
	string key = Action();
	if (key != "null" && last_key == "null")
	{		
		if (key == "up")	{
			snake1.changehead("up");
		}
		if (key == "down") {
			snake1.changehead("down");
		}
		if (key == "left") {
			snake1.changehead("left");
		}
		if (key == "right") {
			snake1.changehead("right");
		}
	}
	if (i > hard) {
		if (snake1.gethead() == "up")
		{
			ROW = ROW - 1;
			if (ROW < 0) {
				ROW = SCREEN_HEIGHT;
			}
		}
		if (snake1.gethead() == "down")
		{
			ROW = ROW + 1;
			if (ROW > SCREEN_HEIGHT) {
				ROW = 0;
			}
		}
		if (snake1.gethead() == "left")
		{
			COLUM = COLUM - 1;
			if (COLUM < 0) {
				COLUM = SCREEN_WIDTH;
			}
		}
		if (snake1.gethead() == "right")
		{
			COLUM = COLUM + 1;
			if (COLUM > SCREEN_WIDTH) {
				COLUM = 0;
			}
		}
		i_snake = i_snake + 1;
		snake1.setsnake(i_snake, ROW, COLUM);
		drawsnake(snake1.getlang());
		i = 1;
	}
	last_key = key;
}

void gameController::upCursor()
{
	i_cursor = i_cursor > 0 ? i_cursor - 1 : 0;
	row = 13 + i_cursor * 2;
}

void gameController::downCursor()
{	
	i_cursor = (i_cursor + 1 < currentPointer->items.size()) ? i_cursor + 1 : currentPointer->items.size()-1;
	row = 13 + i_cursor * 2;
}

string gameController::Action()
{
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 119) {//up
				return "up";
			}
			if (ch == 115) {//down
				return "down";
			}
			if (ch == 97) {//left
				return "left";
			}
			if (ch == 100) {//right
				return "right";
			}
			if (ch == 27) {//esc
				return "esc";
			}
			if (ch == 13) {//esc
				return "enter";
			}
		}
return "null";	
}

void gameController::running()
{
	static string last_key = "null";
	if (i_running == 0)
	{
		this->drawMenu();
		this->drawCursor();
	}
	i_running = i_running++;
	string key = Action();
	if (key!="null" && last_key=="null")
	{
		if (key=="up")
		{
			drawCursor(false);
			upCursor();
			drawCursor();
		}
		if (key == "down")
		{
			drawCursor(false);
			downCursor();
			drawCursor();
		}
		if (key == "enter")
		{
				if (currentPointer->items[i_cursor]->items.size() != 0)
				{
					this->drawMenu(false);
					currentPointer = currentPointer->items[i_cursor];
					this->drawMenu();
				}			
		}
		if (key == "esc")
		{
			if (currentPointer->father != nullptr) {
                this->drawMenu(false);
				currentPointer = currentPointer->father;
				this->drawMenu();
			}					
		}
	}
last_key = key;
}

void gameController::initialize()
{
	screen->clearScreen();
}

void gameController::checkpoint()
{
	int x;
	int y;
	srand(time(0));
	for (int i = 0; i < snake1.getlang(); i++) {
		x = rand() % 80;
	    y = rand() % 45;
		int row = snake1.getsnakerow(i);
		int colum = snake1.getsnakecolum(i);
		if (x== row && y==colum )
		{

		}  
	   checkPoint.setpoint(1,1);
	}	
}
	
void gameController::drawMenu(bool t) {
	if (t)
	{
       for (int i = 0; i < currentPointer->items.size(); i++) {
	screen->setString(13 + i * 2, 35, currentPointer->items[i]->name);
		}
		screen->flushScreen();
	}
	else
	{
		for (int i = 0; i < currentPointer->items.size(); i++) {
			screen->setString(13 + i * 2, 35, "                     ");
		}
		screen->flushScreen();
	}		
}

int Snake::getsnakerow(unsigned int i)
{
	return snakepoint[i%3000].getrow();
}
int Snake::getsnakecolum(unsigned int i)
{
	return snakepoint[i%3000].getcolum();
}

void Snake::setsnake(unsigned int i, unsigned int row, unsigned int colum)
{	
	I = i%3000;
	snakepoint[I].setpoint(row, colum);
}

void Snake::changehead(string head)
{
	if (Snake::head=="up")
	{
		if (head=="down")
		{
			Snake::head = Snake::head;
		}
		else
		{
			Snake::head = head;
		}
	}
	if (Snake::head == "down")
	{
		if (head == "up")
		{
			Snake::head = Snake::head;
		}
		else
		{
			Snake::head = head;
		}
	}
	if (Snake::head == "left")
	{
		if (head == "right")
		{
			Snake::head = Snake::head;
		}
		else
		{
			Snake::head = head;
		}
	}
	if (Snake::head == "right")
	{
		if (head == "left")
		{
			Snake::head = Snake::head;
		}
		else
		{
			Snake::head = head;
		}
	}
}

int Snake::getlang()
{
	return lang;
}

void Snake::score()
{
	lang = lang + 1;
}

string Snake::gethead()
{
	return string(head);
}

point::point()
{
}


void point::setpoint(unsigned int row, unsigned int colum)
{
	Row = row;
	Colum = colum;
}

unsigned int point::getrow()
{
	return Row;
}

unsigned int point::getcolum()
{
	return Colum;
}
