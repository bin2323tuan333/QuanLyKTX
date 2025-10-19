#pragma once


class ManageViewBase
{
public:
	virtual ~ManageViewBase();

	virtual void show() = 0;
	virtual void handleInput(int) = 0;
};