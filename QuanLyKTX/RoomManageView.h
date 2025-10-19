#pragma once
#include "RoomService.h"
#include "ManageViewBase.h"

class RoomManageView : public ManageViewBase
{
private:
	RoomService* roomService;

	string* sidebarRoomList;
	int sidebarRoomSize;
	int sidebarRoomSelected;

public:
	RoomManageView(RoomService*);
	~RoomManageView();

	void show() override; 
	void handleInput(int) override;


private:
	void drawRoomServiceContent(const int&, const int&);
	void drawSidebarRoom(const int&, const int&);

	string GetLine();
	int GetInt();
};