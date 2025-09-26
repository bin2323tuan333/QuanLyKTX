#pragma once
#include "BaseScreen.h"



class AboutUs : public BaseScreen
{
public:
	AboutUs();
	~AboutUs();


	void draw() override;
	void handleClick(int x, int y, BaseScreen*& current) override;
};