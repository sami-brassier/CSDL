#ifndef GRID_HPP
#define GRID_HPP

#include "raylib.h"
#include "Sudoku.hpp"
#include "GameObject.hpp"

// Grid class represents the Sudoku grid and handles drawing and updates
class Grid : public GameObject {
public:
    Grid(int width, int height, int cellSize);  // Constructor
    virtual ~Grid();  // Destructor
    virtual void draw() const override;  // Draws the grid
    virtual void update() override;  // Updates the grid state based on user input

private:
    int width;  // Width of the grid in cells
    int height;  // Height of the grid in cells
    int cellSize;  // Size of each cell in pixels
    Sudoku* sudoku;  // Pointer to the Sudoku object representing the puzzle
    int selectedRow;  // Currently selected row
    int selectedCol;  // Currently selected column
};

#endif // GRID_HPP
