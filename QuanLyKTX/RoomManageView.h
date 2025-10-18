#pragma once
#include "RoomService.h"

class RoomManageView
{
private:
	RoomService* roomService;

	string* sidebarRoomList;
	int sidebarRoomSize;
	int sidebarRoomSelected;

public:
	RoomManageView(RoomService*);
	~RoomManageView();
	void show();
	void handleInput(int);


private:
	void draw();
	void drawRoomServiceContent(const int&, const int&);
	void drawSidebarRoom(const int&, const int&);

	string GetLine();
	int GetInt();
};