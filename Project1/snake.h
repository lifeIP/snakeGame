#pragma once
#include <string>

class snake
{
private:
	int width;
	int height;
	char** field;
	int direction = 0;
	short x = 10, y = 10;
	COORD pos_now = { y,x };
	void setPosition(const char direction) {
		switch (direction)
		{
		case 'u'://UP
			if (x > 1) {
				x--;
			}
			pos_now = {y,x};
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
			std::cout << '@';
			break;
		case 'd'://DOWN
			if (x < 26) {
				x++;
			}
			pos_now = { y,x };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
			std::cout << '@';
			break;
		case 'l'://LEFT
			if (y > 1) {
				y--;
			}
			pos_now = { y,x };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
			std::cout << '@';
			break;
		case 'r'://RIGHT
			if (y < 70) {
				y++;
			}
			pos_now = { y,x };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
			std::cout << '@';
			break;
		default:
			break;
		}
	}

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
			setPosition('u');
			break;
		case 80://DOWN
			setPosition('d');
			break;
		case 75://LEFT
			setPosition('l');
			break;
		case 77://RIGHT
			setPosition('r');
			break;
		default:
			break;
		}
	}
};