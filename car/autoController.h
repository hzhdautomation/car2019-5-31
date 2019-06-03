#pragma once
#include <string>
#include <vector>
#include <map>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "gameController.h"

class path {
private:
	point plan[3000];
public:
	void setpath();
	void automove();
};