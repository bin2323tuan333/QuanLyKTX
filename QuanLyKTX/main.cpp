#include <windows.h>
#include "BaseScreen.h"
#include "HomePage.h"
#include "AboutUs.h"
#include "Position.h"
#include "ConsolaUI.h"
#include <iostream>
using namespace std;

int main() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hInput, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT);

    AccountRepository account;
    LoginService loginService(account);
    account.LoadDataFromFile();


    BaseScreen* current = new HomePage(loginService);
    Position pos;
    pos.setClicked(false);
    int currWidth, currHeight, befWidth = 0, befHeight = 0;



    while (current != nullptr) {
        pos.Update();
        bool d = false;
        if (pos.isClicked()) {
            current->handleClick(pos.getX(), pos.getY(), current);
            d = true;
            pos.setClicked(false);
        }

        currWidth = ConsolaUI::getConsoleWidth();
        currHeight = ConsolaUI::getConsoleHeight();
        if (currWidth != befWidth || currHeight != befHeight || d) 
        {
            ConsolaUI::clearScreen();
            current->draw();
            befWidth = currWidth;
            befHeight = currHeight;
        }

        Sleep(30);
    }
    delete current;
    return 0;
}