#pragma once
#include "ConsolaUI.h"

class BaseView
{
public:
	virtual ~BaseView();
	virtual int show() = 0;
	virtual void handleInput() = 0;
};

