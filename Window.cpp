#include "Window.h"

Window::Window() {
    timeLeft = 0;
    bool atIdle = true;
    idleTime = 0;
    bool idledOverFive = false;
}

Window::~Window() {
    timeLeft = 0;
    atIdle = 0;
    idleTime = 0;
}
