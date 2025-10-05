#pragma once
#include "PageManager.h"

class Application
{
private:
    PageManager* page;
    bool isRunning;
    bool isSignIn;

public:
    Application(PageManager*);
    ~Application();
    void run();
};