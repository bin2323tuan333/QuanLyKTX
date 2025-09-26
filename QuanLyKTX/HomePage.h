#pragma once
#include "BaseScreen.h"
#include "LoginService.h"


class HomePage : public BaseScreen
{
private:
	LoginService& loginService;
public:
	HomePage(LoginService&);
	~HomePage();  

	void draw() override;
	void handleClick(int x, int y, BaseScreen*& current) override;
};