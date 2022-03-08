#pragma once

// The class is implemented in order to create a multiplayer.
class snake
{
private:
	int width;
	int height;
	char** field;
	int direction = 0;
	short x = 10, y = 10;
	bool endGame = false;
	
	COORD pos_now = { y,x };
	
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
			pos_now = {y,x};
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
			std::cout << '@';
			break;

		case 'd'://DOWN
			if (x < 26) {
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
			if (y > 0) {
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
			if (y < 71) {
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

public:
	
	bool it_is_lose() {
		return endGame;
	}

	void ñreate_a_field(int width_enter = 69, int height_enter = 26) {
		width = width_enter; height = height_enter;
		field = new char*[width];
		/*for (int i = 0; i < width; i++) {
			field[i] = new char[height];
		}*/
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