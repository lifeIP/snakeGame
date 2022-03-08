#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>

typedef std::string str;

int main() {
	str s_start_end =  "------------------------------------------------------------------------";
    std::cout << s_start_end << std::endl;
    
    for (int i = 0, j = 1; j < 27; j++) {
        COORD pos_left = { i,j };
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_left);
        std::cout << "|\n";
    }
    
    for(int i = 71, j = 1; j < 27; j++) {
        COORD pos_right = { i,j };
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), pos_right);
        std::cout << "|\n";
    }


    COORD c = { 1,1 };
    int percent = 100000;

    TCHAR szNewTitle[MAX_PATH];
    StringCchPrintf(szNewTitle, MAX_PATH, TEXT("TEST: %s"), TEXT("WHAT?"));
    SetConsoleTitle(szNewTitle);
    /*  for (int i = 0; i <= percent; i++) {
        SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE), c);
        std::cout << "Loaded " << i << "% from " << percent << "%." << std::endl;
        Sleep(20);
    }*/
   


    std::cout << s_start_end << std::endl;
    std::cin >> s_start_end;
}