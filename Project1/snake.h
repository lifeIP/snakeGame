#pragma once
#include <string>

class snake
{
private:
	int sizeSnake;
	std::string colorSnake;
	int width;
	int height;
	char** field;
public:
	bool ñreate_a_field(int width_enter = 69, int height_enter = 26) {
		width = width_enter; height = height_enter;
		field = new char*[width];
		
		for (int i = 0; i < width; i++) {
			field[i] = new char[height];
		}


	}
};

