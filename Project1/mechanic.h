#pragma once

void directionVector(int direction);
void setPosition(const char direction);
void сreate_a_field(int width_enter, int height_enter);
void is_end();
void render_pos();
void appearanceFood();
void setFoodPos();


std::vector <short> part_position_x = { };
std::vector <short> part_position_y = { };
char past_pos = 'r';
int width;
int height;
short size_snake = 5;
short x = 10, y = 20;
bool endGame = false;
char pos = 'r';
bool val = false;
short pos_x, pos_y;
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

	}
}

void oroboros() {

}

void render_pos() {
	if (part_position_x.size() > size_snake) {
		short ix, iy, x, y;
		ix = part_position_x.size() - 1;
		iy = part_position_y.size() - 1;
		x = part_position_x[ix];
		y = part_position_y[iy];
		//search+

		//search-
		if (x == pos_x && y == pos_y) {
			part_position_x.pop_back();
			part_position_y.pop_back();
		}
		else {
			pos_now = { x, y };
			SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
			std::cout << ' ';
			part_position_x.pop_back();
			part_position_y.pop_back();
		}
	}
}

void root_t() {
	while (!endGame) {
		setPosition(pos);
		if (pos == 'r' || pos == 'l') {
			Sleep(100);
		}
		else Sleep(150);
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

void setFoodPos() {
	pos_x = rand() % (width)+2;
	pos_y = rand() % (height)+1;
	pos_now = { pos_x, pos_y };
	SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
	std::cout << '#';
}

void appearanceFood() {
	if (y == pos_x && x == pos_y) {
		size_snake++;
		setFoodPos();
	}
}
bool bs = true;
void setPosition(const char direction) {
	if (bs == true) {
		setFoodPos();
		bs = false;
	}
	char sd = direction;
	if (direction == 'u'&& past_pos=='d'|| direction == 'd' && past_pos == 'u'|| direction == 'r' && past_pos == 'l'|| direction == 'l' && past_pos == 'r') {
		sd = past_pos;
	}
	switch (sd)
	{
	case 'u'://UP
		if (x > 1) {
			x--;
			past_pos = 'u';
		}
		else {
			x--;
			past_pos = 'u';
			endGame = true;
		}
		part_position_y.insert(part_position_y.begin(), x);
		part_position_x.insert(part_position_x.begin(), y);
		render_pos();
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		appearanceFood();
		break;

	case 'd'://DOWN
		
		if (x < height) {
			x++;
			past_pos = 'd';
		}
		else {
			x++;
			past_pos = 'd';
			endGame = true;
		}
		part_position_y.insert(part_position_y.begin(), x);
		part_position_x.insert(part_position_x.begin(), y);
		render_pos();
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		appearanceFood();
		break;

	case 'l'://LEFT
		if (y > 1) {
			y--;
			past_pos = 'l';
		}
		else {
			y--;
			past_pos = 'l';
			endGame = true;
		}
		part_position_y.insert(part_position_y.begin(), x);
		part_position_x.insert(part_position_x.begin(), y);
		render_pos();
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		appearanceFood(); 
		break;

	case 'r'://RIGHT
		if (y < width + 1) {
			y++;
			past_pos = 'r';
		}
		else {
			y++;
			past_pos = 'r';
			endGame = true;
		}
		part_position_y.insert(part_position_y.begin(), x);
		part_position_x.insert(part_position_x.begin(), y);
		render_pos();
		pos_now = { y,x };
		SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_now);
		std::cout << '@';
		appearanceFood();
		break;

	default:
		break;
	}
}

void сreate_a_field(int width_enter = 69, int height_enter = 26) {
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