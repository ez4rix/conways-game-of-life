#pragma once

#include <iostream>
#include <raylib.h>

#include "Click.hpp"

class Button
{
public:

    void Update();

    void Draw();

    void UpdateText();

    std::string content;
    bool paused = 1;
    Rectangle rec = {500, 730, 210, 60};

    Click click;

};