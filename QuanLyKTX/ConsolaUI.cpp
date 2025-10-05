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

// New: Function to draw an input box and get user input
string ConsolaUI::getInput(int x, int y, int w, int h, int textColor, int borderColor) {
    string input;
    setTextColor(borderColor);
    drawBox(x, y, w, h, borderColor);
    gotoXY(x + 1, y + h / 2);
    setTextColor(textColor);
    ShowCursor(true);

    char c;
    int curX = x + 1;
    while (true) {
        c = _getch();
        if (c == 13) break; 
        else if (c == 8) {  
            if (!input.empty()) {
                input.pop_back();
                curX--;
                gotoXY(curX, y + h / 2);
                cout << " ";
                gotoXY(curX, y + h / 2);
            }
        }
        else if (isprint(c) && curX < x + w - 1) { 
            input += c;
            cout << c;
            curX++;
        }
    }
    ShowCursor(false);
    return input;
}



void ConsolaUI::clearScreen() 
{
    system("cls");
}