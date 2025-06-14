#include "Grid.hpp"
#include "simulation.hpp"

void Grid::Draw()
{
    for(int row = 0; row < rows; row++)
    {
        for(int collumn = 0; collumn < collumns; collumn++)
        {
            Color color = cells[row][collumn] ? Color{255, 255, 255, 255} : Color{0,0,0,255};
            DrawRectangle(collumn*cellsize, row*cellsize, cellsize - 1, cellsize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int collum, int value)
{
    if(collum >= 0 && collum < collumns && row >= 0 && row < rows) {
        
        cells[row][collum] = value;
    }
}

int Grid::CountLiveCells()
{
    int liveCells = 0;
    for(int row = 0; row < rows; row++)
    {
        for(int collumn = 0; collumn < collumns; collumn++)
        {
            if(cells[row][collumn]) {liveCells++;}
        }
    }

    return liveCells;
}