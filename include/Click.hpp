#pragma once
#include "raylib.h"

class Click
{
public:

bool pause;

bool IsClicked(Rectangle rec)
{
    return CheckClicked() && IsOver(rec);
}

bool CheckClicked()
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool IsOver(Rectangle rec)
{
    Vector2 mouspos = GetMousePosition();
    return CheckCollisionPointRec(mouspos, rec);
}

};