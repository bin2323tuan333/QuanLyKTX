#pragma once
#include "BaseView.h"

class StudentView : public BaseView
{
private:
	void handleInput() override;
public:
	StudentView();
	~StudentView();

	int show() override;
};



