#pragma once
#include <vector> 

void directionVector(int direction);
void setPosition(const char direction);
void ñreate_a_field(int width_enter, int height_enter);
void is_end();
void render_pos();

std::vector <double> part_position;

int width;
int height;
short x = 10, y = 20;
bool endGame = false;
char pos = 'r';


COORD pos_now = { y,x };

void is_end() {
	short x = 10, y = 10;
	pos_now = { x, y };
	std::string st1{ "This is the end of the snake world :(" };
	SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
	std::cout << st1;
	x = 0; y = height + 5;
	pos_now = { x, y };
	SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
}

void root_s()
{
	int i_switch;
	while (!endGame) {
		if (_getch()) {
			i_switch = static_cast<int>(_getch());
		}
		else i_switch = 0;
		directionVector(i_switch);
		render_pos();
	}
}

void render_pos() {
	
}

void root_t() {
	while (!endGame) {
		setPosition(pos);
		if (pos == 'r' || pos == 'l') {
			Sleep(50);
		}
		else Sleep(100);
	}
	is_end();
}

void directionVector(int direction) {
	switch (direction)
	{
	case 72://UP
		if (pos != 'd') {
			pos = 'u';
		}
		break;
	case 80://DOWN
		if (pos != 'u') {
			pos = 'd';
		}
		break;
	case 75://LEFT
		if (pos != 'r') {
			pos = 'l';
		}
		break;
	case 77://RIGHT
		if (pos != 'l') {
			pos = 'r';
		}
		break;
	default:
		break;
	}
}

void setPosition(const char direction) {
	switch (direction)
	{
	case 'u'://UP
		if (x > 1) {
			x--;

		}
		else {
			x--;
			endGame = true;
		}
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		break;

	case 'd'://DOWN
		if (x < height) {
			x++;

		}
		else {
			x++;
			endGame = true;
		}
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		break;

	case 'l'://LEFT
		if (y > 1) {
			y--;

		}
		else {
			y--;
			endGame = true;
		}
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		break;

	case 'r'://RIGHT
		if (y < width + 1) {
			y++;

		}
		else {
			y++;
			endGame = true;
		}
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		break;

	default:
		break;
	}
}

void ñreate_a_field(int width_enter = 69, int height_enter = 26) {
	width = width_enter; height = height_enter;

	for (short i = 0, j = 0; i < width_enter + 3; i++) {
		COORD pos_up = { i,j };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_up);
		std::cout << "-";
	}

	for (short i = 0, j = 1; j < height_enter + 1; j++) {
		COORD pos_left = { i,j };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_left);
		std::cout << "|\n";
	}

	for (short i = width_enter + 2, j = 1; j < height_enter + 1; j++) {
		COORD pos_right = { i,j };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_right);
		std::cout << "|\n";
	}

	for (short i = 0, j = height_enter + 1; i < width_enter + 3; i++) {
		COORD pos_down = { i,j };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_down);
		std::cout << "-";
	}
}