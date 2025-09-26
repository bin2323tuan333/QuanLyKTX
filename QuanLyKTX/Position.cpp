#include "Position.h"
#include <iostream>
#include <windows.h>
using namespace std;


Position::Position()
{
	Update();
}
Position::~Position()
{

}
void Position::Update() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD record;
    DWORD events;

    if (PeekConsoleInput(hInput, &record, 1, &events) && events > 0) {
        ReadConsoleInput(hInput, &record, 1, &events);

        if (record.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mouse = record.Event.MouseEvent;

            

            if ((mouse.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) &&
                mouse.dwEventFlags == 0) 
            {
                x = mouse.dwMousePosition.X;
                y = mouse.dwMousePosition.Y;
                this->clicked = true;
            }
        }
    }
}

int Position::getX()
{
    return this->x;
}
int Position::getY()
{
    return this->y;
}
bool Position::isClicked()
{
    return this->clicked;
}
void Position::setClicked(bool b)
{
    this->clicked = b;
}