#include <conio.h> 
#include <iostream>

#include "Drawing.h"
#include "gameController.h"

using namespace std; 

gameController gameCtrl;

int main() {
	gameCtrl.initialize();
	while (true)
	{
		Sleep(1);
		//gameCtrl.running();
		gameCtrl.snakemove();
		/*
		if (_kbhit()) {
			char ch = _getch();
			cout << ch;
			if (ch == 27) {//ESC
				//break;
			}
		}
		*/
	}
	system("pause");
	return 0;
}











