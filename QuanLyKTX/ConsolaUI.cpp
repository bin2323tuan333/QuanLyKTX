#include "ConsolaUI.h"


// Ham lay chieu rong cua console
int ConsolaUI::getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left -2;
}

// Ham lay chieu cao cua console
int ConsolaUI::getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top -2;
}

// Di chuyen (x, y) den toa do tren consola
void ConsolaUI::gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hien thi con tro chuot
void ConsolaUI::ShowCursor(bool show) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

// Thay doi mau chu
void ConsolaUI::setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


// Hinh Chu Nhat
void ConsolaUI::drawBox(int x, int y, int w, int h, int borderColor) {
    // Mau Sac
    setTextColor(borderColor);

    // Ve Hinh Chu Nhat
    gotoXY(x, y); cout << char(201);
    gotoXY(x + w, y); cout << char(187);
    gotoXY(x, y + h); cout << char(200);
    gotoXY(x + w, y + h); cout << char(188);
    for (int i = 1; i < w; i++) {
        gotoXY(x + i, y); cout << char(205);
        gotoXY(x + i, y + h); cout << char(205);
    }
    for (int i = 1; i < h; i++) {
        gotoXY(x, y + i); cout << char(186);
        gotoXY(x + w, y + i); cout << char(186);
    }
}

void ConsolaUI::text(int x, int y, const string& content, const int& color)
{
    setTextColor(color);
    gotoXY(x, y);
    cout << content;
}




void ConsolaUI::clearScreen() 
{
    system("cls");
}