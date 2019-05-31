#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

#define SCREEN_HEIGHT 45
#define SCREEN_WIDTH 80

template <typename T>
class point2D {
public:
	T getX() {
		return x;
	}
	T getY() {
		return y;
	}
	void setX(T x) {
		this->x = x;
	}
	void setY(T y) {
		this->y = y;
	}
private:
	T x, y;
};

class image {
public:
	char getPixel(unsigned int row, unsigned int colum) {
		if (row < height && colum < width) {
			return data[row*(width+1) + colum];
		}
	}
	char* data;
	int width;
	int height;
};


class Drawing {
public:
	Drawing();
	void clearScreen();
	void clearArea(unsigned int row, unsigned int colum, unsigned int width, unsigned int height);
	void setPixel(unsigned int row, unsigned int colum, bool status);
	void setChar(unsigned int row, unsigned int colum, char c);
	void setString(unsigned int row, unsigned int colum, std::string str);
	void setImage(unsigned int row, unsigned int colum, unsigned int width, unsigned int height, image img);
	void flushScreen();
private:
	char screen[SCREEN_HEIGHT][SCREEN_WIDTH+1];
};
