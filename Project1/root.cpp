#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include <cstdlib>
#include <vector> 
#include <thread>
#include <time.h>

#include "mechanic.h"
#include "snake.h"

typedef std::string str;

int main() {
    srand(time(NULL));
    //Head name+
    TCHAR NewTitle[MAX_PATH];
    StringCchPrintf(NewTitle, MAX_PATH, TEXT("WHAT? %s"), TEXT("SCORE!"));
    SetConsoleTitle(NewTitle);
    //Head name-
    short i;
    std::cout << "Enter 1";
    std::cin >> i;
    �reate_a_field(50, 26);
    std::thread s(root_s);
    std::thread t(root_t);
    s.join();
    t.join();
}