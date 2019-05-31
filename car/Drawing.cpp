#include "Drawing.h"

Drawing::Drawing() {
	clearScreen();
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		screen[i][SCREEN_WIDTH] = '\0';
	}
}

void Drawing::clearScreen() {
	clearArea(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Drawing::clearArea(unsigned int row, unsigned int colum, unsigned int width, unsigned int height) {
	//limit max
	int startRow = row < SCREEN_HEIGHT ? row : SCREEN_HEIGHT;
	int endRow = startRow + height < SCREEN_HEIGHT ? startRow + height : SCREEN_HEIGHT;
	int startColum = colum < SCREEN_WIDTH ? colum : SCREEN_WIDTH;
	int endColum = startColum + width < SCREEN_WIDTH ? startColum + width : SCREEN_WIDTH;

	for (int i = startRow; i < endRow; i++) {
		for (int j = startColum; j < endColum; j++) {
			screen[i][j] = ' ';
		}
	}
}

void Drawing::setPixel(unsigned int row, unsigned int colum, bool status) {
	//limit max
	if (row < SCREEN_HEIGHT && colum < SCREEN_WIDTH) {
		screen[row][colum] = status == true ? 'A' : ' ';
	}
}

void Drawing::setChar(unsigned int row, unsigned int colum, char c) {
	//limit max
	if (row < SCREEN_HEIGHT && colum < SCREEN_WIDTH) {
		screen[row][colum] = c=='\0'?' ':c;
	}
}

void Drawing::setImage(unsigned int row, unsigned int colum, unsigned int width, unsigned int height, image img) {//char img[][]
	//limit max
	int startRow = row < SCREEN_HEIGHT ? row : SCREEN_HEIGHT;
	int endRow = startRow + height < SCREEN_HEIGHT ? startRow + height : SCREEN_HEIGHT;
	int startColum = colum < SCREEN_WIDTH ? colum : SCREEN_WIDTH;
	int endColum = startColum + width < SCREEN_WIDTH ? startColum + width : SCREEN_WIDTH;

	for (int i = startRow; i < endRow; i++) {
		for (int j = startColum; j < endColum; j++) {
			screen[i][j] = img.getPixel(i - startRow, j - startColum);
		}
	}
}

void Drawing::flushScreen() {
	system("cls");
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		std::cout << screen[i];
		std::cout << std::endl;
	}
}

void Drawing::setString(unsigned int row, unsigned int colum, std::string str){
	for (int i = 0; i < str.size(); i++) {
		setChar(row, colum + i, str[i]);
	}
}