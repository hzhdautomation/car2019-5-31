#include <conio.h> 
#include <iostream>

#include "Drawing.h"
#include "gameController.h"

using namespace std; 

gameController gameCtrl;


int main() {
	//gameCtrl.initialize();
	while (true)
	{
		Sleep(1);
		//gameCtrl.running();
		//gameCtrl.drawcheekpoint(false);
		//gameCtrl.checkpoint();
		gameCtrl.gamestart();
		//gameCtrl.snakemove();
		/*
		if (_kbhit()) {
			char ch = _getch();
			cout << ch;
			if (ch == 27) {//ESC
				//break;
			}
		}
		*/
		/*if (_kbhit()) {
			char ch = _getch();
			if (ch == 119) {//up
				screen.setPixel(x, y, false);
				x = x - 1;
			}
			if (ch == 115) {//down
				screen.setPixel(x, y, false);
				x = x + 1;
			}
			if (ch == 97) {//left
				screen.setPixel(x, y, false);
				y = y - 1;
			}
			if (ch == 100) {//right
				screen.setPixel(x, y, false);
				y = y + 1;
			}
			screen.setPixel(x, y, true);
			screen.flushScreen();
		}*/
	}
		system("pause");
		return 0;
	

}









