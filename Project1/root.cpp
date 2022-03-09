#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
//#include <strsafe.h>

#include "mechanic.h"
#include "snake.h"

typedef std::string str;

int main() {

    //Head name+
    TCHAR NewTitle[MAX_PATH] = TEXT("WHAT?");
    //StringCchPrintf(NewTitle, MAX_PATH, TEXT("TEST: %s"), TEXT("WHAT?"));
    SetConsoleTitle(NewTitle);
    //Head name-

    
    
    snake sk;
    sk.ñreate_a_field(80, 80);

    //switch+
    int i_switch;
    while (!sk.it_is_lose()) {
        if (_getch()) {
            i_switch = static_cast<int>(_getch());
        }
        else i_switch = 0;

        sk.directionVector(i_switch);    //method "directionVector" from the class "snake"
    }
}