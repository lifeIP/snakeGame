#pragma once

// The class is implemented in order to create a multiplayer.
class snake
{
private:
	int width;
	int height;
	bool** field;
	short x = 10, y = 20;
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
			if (y < width+1) {
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
		
		for (short i = 0, j = 0; i < width_enter+3; i++) {
			COORD pos_up = { i,j };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_up);
			std::cout << "-";
		}

		for (short i = 0, j = 1; j < height_enter+1; j++) {
			COORD pos_left = { i,j };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_left);
			std::cout << "|\n";
		}

		for (short i = width_enter+2, j = 1; j < height_enter+1; j++) {
			COORD pos_right = { i,j };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_right);
			std::cout << "|\n";
		}

		for (short i = 0, j = height_enter+1; i < width_enter+3; i++) {
			COORD pos_down = { i,j };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_down);
			std::cout << "-";
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