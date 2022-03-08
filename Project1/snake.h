#pragma once
#include <string>

class snake
{
private:
	int sizeSnake=0;
	int width;
	int height;
	char** field;
	void ouroboros() {}
	void snakeGrowth() {}
public:
	void ñreate_a_field(int width_enter = 69, int height_enter = 26) {
		width = width_enter; height = height_enter;
		field = new char*[width];
		
		for (int i = 0; i < width; i++) {
			field[i] = new char[height];
		}
	}
	void directionVector(int direction) {
		switch (direction)
		{
		case 72://UP
			break;
		case 80://DOWN
			break;
		case 75://LEFT
			break;
		case 77://RIGHT
			break;
		default:
			break;
		}
	}
};

