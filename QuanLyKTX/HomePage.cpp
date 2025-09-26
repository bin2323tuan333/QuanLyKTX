#include "HomePage.h"
#include "Login.h"
#include "AboutUs.h"
#include "ConsolaUI.h"

HomePage::HomePage(LoginService& lg)
    : loginService(lg)
{}
HomePage::~HomePage() {}

void HomePage::draw() 
{
    int height = ConsolaUI::getConsoleHeight();
    int width = ConsolaUI::getConsoleWidth();
    ConsolaUI::ShowCursor(false);


    if (height >= 3)
    {
        ConsolaUI::drawBox(1, 1, width, height, 15);
        ConsolaUI::text(5, 3, "Trang Chu");
        ConsolaUI::gotoXY(5, 4);
        for (int i = 0; i < 9; i++)
            cout << char(205);
        ConsolaUI::text(width - 10, 3, "Dang Nhap");
        ConsolaUI::text(20, 3, "Gioi Thieu");

    }
    if (height >= 15 && width >= 50)
    {
        ConsolaUI::drawBox(10, 6, width - 18, height - 6, 15);
        ConsolaUI::text(width / 2 - 12, 8, "PBL2 Do an co so lap trinh");
        ConsolaUI::text(width / 2 - 12, 11, "Ung Dung Quan Ly Ky Tuc Xa");
        ConsolaUI::text(width / 2 - 7, height - 2, "Da Nang 9/2025");
    }
    if (height >= 20 && width >= 80)
    {
        ConsolaUI::text(width - 60, height - 6, "GVHD: TS. Truong Ngoc Chau");
        ConsolaUI::text(width - 60, height - 5, "Pham Quoc Tuan             24T_DT4");
        ConsolaUI::text(width - 60, height - 4, "Nguyen View Nhat Long      24T_DT4");
    }
}



void HomePage::handleClick(int x, int y, BaseScreen*& current) 
{
    int width = ConsolaUI::getConsoleWidth();
    ConsolaUI::text(width - 20, 3, to_string(x) + " " + to_string(y));
    // "Gioi Thieu"
    if ((y == 3 || y == 4) && (x >= 20 && x <= 30)) {
        delete current;
        current = new AboutUs();
        return;
    }
    // "Dang Nhap"
    if ((y == 3 || y == 4) && (x >= width - 10 && x <= width - 1)) {
        delete current;
        current = new Login(this->loginService);
        return;
    }
}