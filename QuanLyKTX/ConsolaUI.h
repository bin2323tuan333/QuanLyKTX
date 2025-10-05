#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

class ConsolaUI {
public:
    static int getConsoleWidth();
    static int getConsoleHeight();
    static void gotoXY(int, int);
    static void ShowCursor(bool);
    static void setTextColor(int);
    static void drawBox(int, int, int, int, int);
    static void text(int, int, const string&, const int&);
    static string getInput(int, int, int, int, int, int);
    static void clearScreen();
};