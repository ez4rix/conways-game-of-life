#pragma once
#include "raylib.h"

class Click
{
public:

bool pause;

bool CheckClicked(Rectangle rec, bool pause)
{
    std::cout << "oui" << std::endl;
    if(IsClick() && IsOver(rec)) return !pause;
    else return pause; 
}

bool IsClick()
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool IsOver(Rectangle rec)
{
    Vector2 mouspos = GetMousePosition();
    return CheckCollisionPointRec(mouspos, rec);
}

};