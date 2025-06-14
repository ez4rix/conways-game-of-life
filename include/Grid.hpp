#pragma once

#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <vector>

#include "Pause.hpp"
#include "Click.hpp"

class Grid
{
public:
    Grid(int _cellsize, int width, int height) : cellsize(_cellsize), rows(height/cellsize), collumns(width/cellsize), cells(rows, std::vector<int>(collumns, 0)) {};

    Click click;

    void Draw();
    void SetValue(int row, int collum, int value);
    

    int CountLiveCells();

    int cellsize;
    int rows;
    int collumns;
    std::vector<std::vector<int>> cells;
};
