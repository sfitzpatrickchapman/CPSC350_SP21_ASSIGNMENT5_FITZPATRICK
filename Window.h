#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
using namespace std;

class Window {
public:
    Window();
    ~Window();

    int timeLeft;
    bool atIdle;
    int idleTime;
    bool idledOverFive;
};

#endif
