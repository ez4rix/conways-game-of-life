#pragma once

#include "Click.hpp"

class Button
{
public:
    Button(Rectangle rec, std::string Text1, std::string Text2, int fontSize = 20)
        : rec(rec),
          content(Text1),
          Text1(Text1),
          Text2(Text2)
    {
        TextToggleOnClick = false;
        TextChangeOnClick = false;
        pressed = false;
        color = WHITE;
        fontColor = BLACK;
    }

    Click click;
    Rectangle rec;

    std::string content;
    std::string Text1;
    std::string Text2;

    bool TextToggleOnClick;
    bool toggle;
    bool TextChangeOnClick;

    bool pressed;

    Color color;
    int fontSize = 20;
    Color fontColor;
    int offsetX = 10;
    int offsetY = 20;


    void Draw()
    {
        DrawRectangleRec(rec, color);
        DrawText(content.c_str(), rec.x + offsetX, rec.y + offsetY, fontSize, fontColor);
    }


    void Update()
    {
        Draw();
        UpdateText();
    }

    void UpdateText()
    {
        if(!TextToggleOnClick && !TextChangeOnClick) return;

        pressed = click.IsClicked(rec);
        
        if(pressed)
        {
            if(TextChangeOnClick) 
            {
                pressed == 0 ? content = Text1 : content = Text2;
            }
            if(TextToggleOnClick) 
            {
                toggle == false ? content = Text1 : content = Text2;
                toggle = !toggle;
            }
        }
    }

};