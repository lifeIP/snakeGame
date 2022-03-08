#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>

#include "mechanic.h"
#include "snake.h"

typedef std::string str;

int main() {
//Head name+
    TCHAR NewTitle[MAX_PATH];
    StringCchPrintf(NewTitle, MAX_PATH, TEXT("TEST: %s"), TEXT("WHAT?"));
    SetConsoleTitle(NewTitle);
//Head name-
        

//field of play+
    for (short i = 0, j = 0; i < 72; i++) {
        COORD pos_up = { i,j };
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_up);
        std::cout << "-";
    }
    
    for (short i = 0, j = 1; j < 27; j++) {
        COORD pos_left = { i,j };
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_left);
        std::cout << "|\n";
    }
    
    for(short i = 71, j = 1; j < 27; j++) {
        COORD pos_right = { i,j };
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_right);
        std::cout << "|\n";
    }

    for (short i = 0, j = 27; i < 72; i++) {
        COORD pos_down = { i,j };
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_down);
        std::cout << "-";
    }
//field of play-

    //69w/26h

    /*COORD c = {1,1};
    int percent = 100000;
      for (int i = 0; i <= percent; i++) {
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), c);
        std::cout << "Loaded " << i << "% from " << percent << "%." << std::endl;
        Sleep(20);
    }*/
}