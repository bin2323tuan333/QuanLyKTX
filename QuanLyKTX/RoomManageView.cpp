#include "RoomManageView.h"
#include "ConsolaUI.h"
#include <sstream>

RoomManageView::RoomManageView(RoomService* roomService)
	:roomService(roomService)
{
	this->sidebarRoomSelected = 0;
	this->sidebarRoomSize = 2;
	this->sidebarRoomList = new string[this->sidebarRoomSize]
	{
		"Xem Danh Sach Phong",
		"Loc Theo Trang Thai"
		//Xem Chi Tiet Phong
	};
}

RoomManageView::~RoomManageView()
{
	delete[] this->sidebarRoomList;
}

void RoomManageView::handleInput(int key)
{
	if (key == 72 || key == 80)
	{
		this->sidebarRoomSelected = (this->sidebarRoomSelected + (key == 72 ? -1 : 1) + this->sidebarRoomSize) % this->sidebarRoomSize;
	}
}

void RoomManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarRoom(width, height);
	drawRoomServiceContent(width, height);
}

void RoomManageView::drawRoomServiceContent(const int& width, const int& height)
{
	switch (this->sidebarRoomSelected)
	{
	case 0:
		ConsolaUI::text(30, 7, "XEM DANH SACH PHONG:", 14);
		break;
	case 1:
		ConsolaUI::text(30, 7, "LOC THEO TRANG THAI:", 14);
		break;
	}
}
void RoomManageView::drawSidebarRoom(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	ConsolaUI::text(5, 8, *(this->sidebarRoomList), (0 == this->sidebarRoomSelected) ? 11 : 8);
	ConsolaUI::text(5, 12, *(this->sidebarRoomList + 1), (1 == this->sidebarRoomSelected) ? 11 : 8);
}

string RoomManageView::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true) {
		int key = _getch();
		if (key == '\r' || key == '\n') break;
		if (key == '\b') {
			if (ss.length() > 0) {
				ss.pop_back();
				cout << "\b \b";
			}
		}
		else {
			ss += char(key);
			cout << char(key);
		}
	}
	ConsolaUI::ShowCursor(false);
	return ss;
}

int RoomManageView::GetInt() {
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}