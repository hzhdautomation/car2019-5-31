#include <conio.h> 
#include <iostream>
#include "Drawing.h"
#include "gameController.h"

using namespace std; 

gameController gameCtrl;

int main() {
	while (true)
	{
		Sleep(1);
		gameCtrl.gamestart();
	}
		system("pause");
		return 0;
}









