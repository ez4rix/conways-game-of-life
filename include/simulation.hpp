#pragma once
#include "Grid.hpp"

class Simulation
{
public:

    Simulation(int cellsize, int width, int height) : grid(cellsize, width, height) {rec = {0, 0, float(cellsize) * width, float(cellsize) * height}; };

    void Draw();
    void SetCellValue(int row, int collumn, int value);
    int CountNeighbours(int row, int collumn);

    void NextGeneation();

    void ClickToogleCells();

    Rectangle rec;

    Click click;
    Grid grid;
};