#include "HomePage.h"
#include "Login.h"
#include "AboutUs.h"
#include "ConsolaUI.h"


AboutUs::AboutUs()
{
}
AboutUs::~AboutUs()
{

}


void AboutUs::draw()
{
    int height = ConsolaUI::getConsoleHeight();
    int width = ConsolaUI::getConsoleWidth();
    ConsolaUI::ShowCursor(false);

    if (height >= 3)
    {
        ConsolaUI::drawBox(1, 1, width, height, 14);
        ConsolaUI::text(5, 3, "Trang Chu");
        ConsolaUI::text(width - 10, 3, "Dang Nhap");
        ConsolaUI::text(20, 3, "Gioi Thieu");
        ConsolaUI::gotoXY(20, 4);
        for (int i = 0; i < 10; i++)
            cout << char(205);
    }
}


void AboutUs::handleClick(int x, int y, BaseScreen*& current)
{
    int width = ConsolaUI::getConsoleWidth();
    ConsolaUI::text(width - 20, 3, to_string(x) + " " + to_string(y));
    // "Trang Chu"
    if ((y == 3 || y == 4) && (x >= 5 && x <= 14)) {
        delete current;
       // current = new HomePage();
        return;
    }
    // "Dang Nhap"
    if ((y == 3 || y == 4) && (x >= width - 10 && x <= width - 1)) {
        delete current;
        //current = new Login();
        return;
    }
}