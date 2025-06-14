#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int collumn, int value)
{
    grid.SetValue(row, collumn, value);
}

int Simulation::CountNeighbours(int row, int collumn)
{
    int liveNeighbours = 0;

    std::vector<std::pair<int, int>> neighboursOffset = 
    {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (const auto& offset : neighboursOffset) 
    {
        int nRow = row + offset.first;
        int nCol = collumn + offset.second;

        // ✅ Check bounds before accessing grid
        if (nRow >= 0 && nRow < grid.rows && nCol >= 0 && nCol < grid.collumns) 
        {
            if (grid.cells[nRow][nCol]) 
            {
                liveNeighbours++;
            }
        }
    }
    return liveNeighbours;   
}

void Simulation::ClickToogleCells()
{
    if(!click.CheckClicked(rec, 0)) return;

    Vector2 mousePos = GetMousePosition();
    int row = mousePos.y / grid.cellsize;
    int column = mousePos.x / grid.cellsize;

    // ✅ Bounds check
    if (row < 0 || row >= grid.rows || column < 0 || column >= grid.collumns)
        return;

    bool currentVal = grid.cells[row][column];
    grid.SetValue(row, column, !currentVal);
}


void Simulation::NextGeneation()
{
    Grid BufGrid = grid;
    for(int row = 0; row < BufGrid.rows; row++)
    {
        for(int collumn = 0; collumn < BufGrid.collumns; collumn++)
        {
            int live_neighbours = CountNeighbours(row, collumn);

            if(BufGrid.cells[row][collumn])
            {
                if(live_neighbours < 2) {BufGrid.cells[row][collumn] = 0;}
                if (live_neighbours == 2 || live_neighbours == 3) {BufGrid.cells[row][collumn] = 1;}
                if(live_neighbours > 3) {BufGrid.cells[row][collumn] = 0;}
            }
            else
            {
                if(live_neighbours == 3) {BufGrid.cells[row][collumn] = 1;}
            }
        }
    }
    grid = BufGrid;
}
