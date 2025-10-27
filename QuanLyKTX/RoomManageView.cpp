#include "RoomManageView.h"
#include "ConsolaUI.h"
#include <sstream>

RoomManageView::RoomManageView(RoomService* roomService)
	:roomService(roomService)
{
	this->sidebarRoomSelected = 0;
	this->sidebarRoomSize = 4;
	this->sidebarRoomList = new string[this->sidebarRoomSize]
	{
		"Xem Danh Sach Phong",
		"Tim Kiem ID Phong",
		"Chuyen Phong Cho SV"
	};

	this->roomListIndex = 0;
	this->maxPage = 0;

	this->roomIDToSearch = 0;

	this->studentIDToNewRoom = 0;
}

RoomManageView::~RoomManageView()
{
	delete[] this->sidebarRoomList;
}

void RoomManageView::show()
{
	int width = ConsolaUI::getConsoleWidth();
	int height = ConsolaUI::getConsoleHeight();
	drawSidebarRoom(width, height);
	drawRoomServiceContent(width, height);
}

void RoomManageView::handleInput(int key)
{
	if (key == 72 || key == 80)
	{
		this->sidebarRoomSelected = (this->sidebarRoomSelected + (key == 72 ? -1 : 1) + this->sidebarRoomSize) % this->sidebarRoomSize;
	}

	if (this->sidebarRoomSelected == 0)
	{
		if (key == 'Q' || key == 'q')
		{
			if (this->roomListIndex > 0) (this->roomListIndex)--;
		}
		else if (key == 'P' || key == 'p')
		{
			if (this->roomListIndex < this->maxPage) (this->roomListIndex)++;
		}
	}
	else if (this->sidebarRoomSelected == 1)
	{
		if (key == 'F' || key == 'f')
		{
			ConsolaUI::gotoXY(66, 9);
			this->roomIDToSearch = GetInt();
		}
	}
	else if (this->sidebarRoomSelected == 2)
	{
		if (key == 'F' || key == 'f')
		{
			ConsolaUI::gotoXY(66, 9);
			this->studentIDToNewRoom = GetInt();
		}
	}
}

void RoomManageView::drawRoomServiceContent(const int& width, const int& height)
{

	switch (this->sidebarRoomSelected)
	{
	case 0:
	{
		ConsolaUI::text(30, 7, "XEM DANH SACH PHONG:", 14);
		LinkedList<Room> list = this->roomService->GetAll();

		if (list.getSize() == 0) 
		{
			ConsolaUI::text(33, 9, "Khong co phong nao trong danh sach!", 12);
		}
		else
		{
			int itemsPerPage = height - 13;
			int totalPages = (list.getSize() + itemsPerPage - 1) / itemsPerPage;
			this->maxPage = totalPages - 1;
			ConsolaUI::text(33, 8, "ID", 11);
			ConsolaUI::text(40, 8, "Ten Phong", 11);
			ConsolaUI::text(53, 8, "Loai", 11);
			ConsolaUI::text(65, 8, "So Nguoi", 11);
			ConsolaUI::text(80, 8, "Tang", 11);
			ConsolaUI::text(90, 8, "Toa Nha", 11);
			ConsolaUI::text(105, 8, "Trang Thai", 11);
			for (int i = 0; i < itemsPerPage; i++)
			{
				int yPos = 9 + i;
				if (i + roomListIndex * itemsPerPage < list.getSize())
				{
					Room* room = list.getAt(i + roomListIndex * itemsPerPage);
					ConsolaUI::text(33, yPos, to_string(room->getRoomID()), 15);
					ConsolaUI::text(40, yPos, room->getRoomName(), 15);
					ConsolaUI::text(53, yPos, room->getRoomType(), 15);
					ConsolaUI::text(65, yPos, to_string(room->getCurrentOccupancy()) + "/" + to_string(room->getCapacity()), (room->getCurrentOccupancy() == room->getCapacity()) ? 6 : 10);
					ConsolaUI::text(80, yPos, to_string(room->getFloor()), 15);
					ConsolaUI::text(90, yPos, room->getBuilding(), 15);
					ConsolaUI::text(105, yPos, room->getIsActive() ? "Hoat dong" : "Khong HD", room->getIsActive() ? 10 : 12);
				}
				else break;
			}
			ConsolaUI::text(60, height - 3, "Trang " + to_string(this->roomListIndex + 1) + "/" + to_string(totalPages), 7);
			ConsolaUI::text(35, height - 1, "[ Q ] Trang Truoc", 3);
			ConsolaUI::text(75, height - 1, "[ P ] Trang Sau", 3);
		}
		break;
	}
	case 1:
	{
		ConsolaUI::text(30, 7, "TIM KIEM THEO ID PHONG", 14);
		ConsolaUI::text(35, 9, "[F] Nhap Ma Phong: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);
		Room* roomToUpdate = this->roomService->SearchByID(this->roomIDToSearch);
		if (this->roomIDToSearch != 0)
		{
			if (roomToUpdate != nullptr)
			{
				ConsolaUI::text(37, 11, "Phong:    " + roomToUpdate->getRoomName(), 9);
				ConsolaUI::text(37, 12, "So Nguoi: " + to_string(roomToUpdate->getCurrentOccupancy()) + "/" + to_string(roomToUpdate->getCapacity()), 9);
				LinkedList<Student> studentList = this->roomService->GetStudentsInRoom(this->roomIDToSearch);
				if (studentList.getSize() > 0)
				{
					int i = 0;
					for (ListNode<Student>* p = studentList.getHead(); p != nullptr; p = p->next)
					{
						ConsolaUI::text(40, 14 + i * 2, to_string((p->value).getStudentID()) + " - " + (p->value).getFullName(), 15);
					}
				}
				else 
				{
					ConsolaUI::text(40, 15, "Chua co sinh vien nao trong phong.", 15);
				}
			}
			else
			{
				ConsolaUI::text(35, 11, ">> KHONG TIM THAY PHONG: " + to_string(this->roomIDToSearch) + " <<", 12);
			}
		}
		break;
	}
	case 2:
	{
		ConsolaUI::text(30, 7, "CHUYEN PHONG CHO SINH VIEN:", 14);
		ConsolaUI::text(35, 9, "[F] Nhap Ma So Sinh Vien: ", 15);
		ConsolaUI::drawBox(65, 8, 25, 2, 15);
		if (this->studentIDToNewRoom != 0)
		{

		}
		break;
	}
	}
}
void RoomManageView::drawSidebarRoom(const int& width, const int& height)
{
	ConsolaUI::drawBox(2, 6, 25, height - 7, 7);
	if (1 != this->sidebarRoomSelected)
	{
		ConsolaUI::text(5, 8, *(this->sidebarRoomList), (0 == this->sidebarRoomSelected) ? 11 : 8);
		ConsolaUI::text(5, 10, *(this->sidebarRoomList + 1), (1 == this->sidebarRoomSelected) ? 11 : 8);
		ConsolaUI::text(5, 12, *(this->sidebarRoomList + 2), (2 == this->sidebarRoomSelected) ? 11 : 8);
		ConsolaUI::text(5, 14, *(this->sidebarRoomList + 3), (3 == this->sidebarRoomSelected) ? 11 : 8);
	}
	else
	{
		ConsolaUI::text(5, 8, *(this->sidebarRoomList), (0 == this->sidebarRoomSelected) ? 11 : 8);
		ConsolaUI::text(5, 10, *(this->sidebarRoomList + 1), (1 == this->sidebarRoomSelected) ? 11 : 8);
		ConsolaUI::text(5, 12, *(this->sidebarRoomList + 2), (2 == this->sidebarRoomSelected) ? 11 : 8);
	}
}

string RoomManageView::GetLine()
{
	string ss;
	ConsolaUI::ShowCursor(true);
	while (true) 
	{
		int key = _getch();
		if (key == '\r' || key == '\n') break;
		if (key == '\b') 
		{
			if (ss.length() > 0) 
			{
				ss.pop_back();
				cout << "\b \b";
			}
		}
		else 
		{
			ss += char(key);
			cout << char(key);
		}
	}
	ConsolaUI::ShowCursor(false);
	return ss;
}

int RoomManageView::GetInt() 
{
	string inputString = GetLine();
	stringstream ss(inputString);
	int result = 0;
	ss >> result;
	return result;
}