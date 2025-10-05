#include "HomePage.h"
#include "ConsolaUI.h"
#include <conio.h>
HomePage::HomePage()
{
	this->menuSelected = 0;
	this->menuSize = 3;
	this->menuList = new string[this->menuSize]
	{
		"Trang Chu",
		"Gioi Thieu",
		"Dang Nhap",
	};
}
HomePage::~HomePage()
{
	delete[] this->menuList;
}


int HomePage::show()
{
	while (true)
	{
		drawHomePage();

		int key = _getch();
		if (key == 0 || key == 224) // Phim mui ten
		{
			key = _getch();
			handleArrowKeys(key, this->menuSelected, this->menuSize);
		}
		else
		{
			if (handleNormalKeys(key, this->menuSelected, this->menuSize))
			{
			}
		}
	}
}
void HomePage::drawHomePage()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();

	ConsolaUI::clearScreen();
	ConsolaUI::ShowCursor(false);
	ConsolaUI::drawBox(0, 0, width, height, 7);

	// Vẽ các thành phần
	drawHeader(width, height);
	switch (menuSelected)
	{
	case 0:
		drawHomeContent(width, height);
		break;
	case 1:
		drawAboutUsContent(width, height);
		break;
	case 2:
		drawLoginContent(width, height);
		break;
	}
	
	drawFooter(width, height);
}

void HomePage::drawLoginContent(const int& width, const int& height)
{

}
void HomePage::drawAboutUsContent(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 15, 6, "===== GIOI THIEU MON HOC =====", 14);

	ConsolaUI::text(width / 2 - 13, 8, "PBL2: Do an co so lap trinh", 15);

	ConsolaUI::text(width / 2 - 27, 10, "De Tai Thuc Hien: Ung Dung Quan Ly Ki Tuc Xa Sinh Vien", 15);

	ConsolaUI::text(width / 5, 16, "GIANG VIEN HUONG DAN:", 13);
	ConsolaUI::text(width / 3 + 10, 16, "TS. Truong Ngoc Chau", 15);

	ConsolaUI::text(width / 5, 19, "SINH VIEN THUC HIEN:", 6);
	ConsolaUI::text(width / 3 + 10, 19, "Pham Quoc Tuan", 15);
	ConsolaUI::text(width / 3 + 35, 19, "Lop: 24T_DT4", 15);
	ConsolaUI::text(width / 3 + 55, 19, "MSSV: 102240229", 15);
	ConsolaUI::text(width / 3 + 10, 20, "Nguyen Viet Nhat Long", 15);
	ConsolaUI::text(width / 3 + 35, 20, "Lop: 24T_DT4", 15);
	ConsolaUI::text(width / 3 + 55, 20, "MSSV: 102240229", 15);


	ConsolaUI::text(width / 2 - 8 , height - 1, "Da Nang, 10/2025", 15);

}

void HomePage::drawHomeContent(const int& width, const int& height)
{
	ConsolaUI::text(5, 7, "THONG TIN CHUNG", 3);
	ConsolaUI::text(7, 8, "$ Ky tuc xa truong Dai hoc Bach Khoa Da Nang.", 15);
	ConsolaUI::text(7, 9, "$ Voi co so vat chat hien dai, moi truong hoc tap va sinh hoat lanh manh.", 15);

	ConsolaUI::text(5, 12, "CAC KHU KY TUC XA", 2);
	ConsolaUI::text(7, 13, "$ Toa Nha A: 5 tang - 120 phong", 15);
	ConsolaUI::text(7, 14, "$ Toa Nha B: 5 tang - 120 phong", 15);
	ConsolaUI::text(7, 15, "$ Toa Nha C: 5 tang - 120 phong", 15);


	ConsolaUI::text(5, 18, "TIEN ICH & DICH VU", 6);
	ConsolaUI::text(7, 19, "$ Cung cap wifi toan khu", 15);
	ConsolaUI::text(7, 20, "$ Thu vien 3 tang", 15);
	ConsolaUI::text(7, 21, "$ Khu vui choi giai tri", 15);
	ConsolaUI::text(7, 22, "$ Cang tin dat chuan quoc te", 15);
	ConsolaUI::text(7, 23, "$ Phong gym & the thao", 15);
}

void HomePage::drawHeader(const int& width, const int& height)
{
	ConsolaUI::setTextColor(15);
	ConsolaUI::text(10, 2, "HE THONG QUAN LY KI TUC XA", 13);
	drawMenuItems(width, height);
}

void HomePage::drawMenuItems(const int& width, const int& height)
{
	ConsolaUI::drawBox(1, 3, width - 2, 2, 7);
	ConsolaUI::text(5, 4, *(this->menuList), (0 == menuSelected) ? 1 : 8);
	ConsolaUI::text(35, 4, *(this->menuList + 1), (1 == menuSelected) ? 1 : 8);
	ConsolaUI::text(65, 4, *(this->menuList + 2), (2 == menuSelected) ? 1 : 8);
}

void HomePage::drawFooter(const int& width, const int& height)
{
	ConsolaUI::text(width / 2 - 27, height + 1, "Su dung cac phim [<-] [->] de di chuyen giua cac trang", 2);
}

void HomePage::drawSelectedItem(int index, bool isSelected)
{

}
void HomePage::handleArrowKeys(int key, int& index, const int& size)
{
	switch (key)
	{
	case 75:
		index = (index - 1 + size) % size;
		break;
	case 77:
		index = (index + 1) % size;
		break;
	}
}

bool HomePage::handleNormalKeys(int key, int& index, const int& size)
{
	switch (key)
	{
	case 13:
		return true;
	case 27:
		index = -1;
		return true;
	default:
		if (key >= '1' && key <= '9')
		{
			int num = key - '1';
			if (num < size)
			{
				index = num;
				return true;
			}
		}
		return false;
	}
}