#pragma once

class BaseScreen 
{
public:
    virtual void draw() = 0;
    virtual void handleClick(int x, int y, BaseScreen*& current) = 0;
    virtual ~BaseScreen();
};
