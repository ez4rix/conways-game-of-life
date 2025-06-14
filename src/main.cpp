#include <iostream>
#include "simulation.hpp"
#include "Pause.hpp"

int main()
{
    const int screenWidth = 720;
    const int screenHeight = 800;
    const int cellSize = 30;
    const Color background = {55,55,55,255};

    InitWindow(screenWidth, screenHeight, "Game of life");
    SetTargetFPS(12);

    Simulation simulation{cellSize, 720, 720};
    
    simulation.SetCellValue(5, 2, 1);
    simulation.SetCellValue(5, 3, 1);
    simulation.SetCellValue(5, 4, 1);

    Button pause;

    int generation = 0;
    int liveCells = 0;




    std::vector<std::pair<int, int>> gosperGliderGun = {
    {5, 1}, {5, 2}, {6, 1}, {6, 2},

    {5, 11}, {6, 11}, {7, 11},
    {4, 12}, {8, 12},
    {3, 13}, {9, 13},
    {3, 14}, {9, 14},
    {6, 15},
    {4, 16}, {8, 16},
    {5, 17}, {6, 17}, {7, 17},
    {6, 18},

    {3, 21}, {4, 21}, {5, 21},
    {3, 22}, {4, 22}, {5, 22},
    {2, 23}, {6, 23},
    {1, 25}, {2, 25}, {6, 25}, {7, 25},

    {3, 35}, {4, 35},
    {3, 36}, {4, 36}
    };

    for (auto [row, col] : gosperGliderGun) 
    {
        simulation.grid.cells[row][col] = 1;
    }

    while (!WindowShouldClose())
    {
        //Draw/update all the object
        BeginDrawing();
            
        pause.Update();
        simulation.Draw();

        DrawText(TextFormat("live cells: %d", liveCells), 10, 730, 20, WHITE);
        DrawText(TextFormat("generation: %d", generation), 10, 760, 20, WHITE);

        if(!pause.paused)
        {
            simulation.NextGeneation();
            generation++;
        }
        else
        {
            simulation.ClickToogleCells();
        }

        ClearBackground(background);        
        EndDrawing();
        
        liveCells = simulation.grid.CountLiveCells();

    }
    return 0;
}