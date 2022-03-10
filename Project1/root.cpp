#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>

#include <thread>

#include "mechanic.h"
#include "snake.h"

typedef std::string str;

int main() {
    //Head name+
    TCHAR NewTitle[MAX_PATH];
    StringCchPrintf(NewTitle, MAX_PATH, TEXT("WHAT? %s"), TEXT("SCORE!"));
    SetConsoleTitle(NewTitle);
    //Head name-

    ñreate_a_field(50, 26);
    std::thread s(root_s);
    std::thread t(root_t);
    s.join();
    t.join();
    void this_is_end();
}