#include "Pause.hpp"

void Button::Update()
{
    Draw();
    paused = click.CheckClicked(rec, paused);
    UpdateText();
}

void Button::Draw()
{
    DrawRectangleLinesEx(rec, 1 ,WHITE);
    DrawText(content.c_str(), rec.x + 20, rec.y + 10, 40, WHITE);
}

void Button::UpdateText()
{
    if(paused) {content = "pause";} else {content = "play";}
}
