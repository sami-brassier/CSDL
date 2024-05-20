#include "Grid.hpp"
#include <string>

// Constructor for the Grid class
Grid::Grid(int width, int height, int cellSize) : width(width), height(height), cellSize(cellSize) {
    sudoku = new Sudoku();  // Initialize a new Sudoku puzzle
    selectedRow = 0;  // Initialize selected row
    selectedCol = 0;  // Initialize selected column
}

// Destructor for the Grid class
Grid::~Grid() {
    delete sudoku;  // Clean up dynamically allocated Sudoku object
}

// Draw the grid and its current state
void Grid::draw() const {
    // Draw each cell in the Sudoku grid
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // Draw the cell border
            DrawRectangleLinesEx(
                (Rectangle){(float)(col * cellSize), (float)(row * cellSize), (float)cellSize, (float)cellSize}, 
                1, BLACK
            );
            
            // Draw the cell value if it's not zero (empty)
            if (sudoku->getCell(row, col) != 0) {
                DrawText(
                    std::to_string(sudoku->getCell(row, col)).c_str(), 
                    col * cellSize + 20, row * cellSize + 20, cellSize / 2, BLACK
                );
            }
        }
    }

    // Draw thick green borders around each 3x3 subgrid
    for (int gridRow = 0; gridRow < 3; ++gridRow) {
        for (int gridCol = 0; gridCol < 3; ++gridCol) {
            int startX = gridCol * 3 * cellSize;
            int startY = gridRow * 3 * cellSize;
            int endX = 3 * cellSize;
            int endY = 3 * cellSize;

            DrawRectangleLinesEx(
                (Rectangle){(float)startX, (float)startY, (float)endX, (float)endY}, 
                3, GREEN
            );
        }
    }

    // Highlight the currently selected cell with a red border
    DrawRectangleLinesEx(
        (Rectangle){(float)(selectedCol * cellSize), (float)(selectedRow * cellSize), (float)cellSize, (float)cellSize}, 
        3, RED
    );
}

// Update the grid state based on user input
void Grid::update() {
    // Change the selected cell based on arrow key inputs
    if (IsKeyPressed(KEY_UP) && selectedRow > 0) selectedRow--;
    if (IsKeyPressed(KEY_DOWN) && selectedRow < 8) selectedRow++;
    if (IsKeyPressed(KEY_LEFT) && selectedCol > 0) selectedCol--;
    if (IsKeyPressed(KEY_RIGHT) && selectedCol < 8) selectedCol++;

    // Set the value of the selected cell based on number key inputs
    if (IsKeyPressed(KEY_ONE)) sudoku->setCell(selectedRow, selectedCol, 1);
    if (IsKeyPressed(KEY_TWO)) sudoku->setCell(selectedRow, selectedCol, 2);
    if (IsKeyPressed(KEY_THREE)) sudoku->setCell(selectedRow, selectedCol, 3);
    if (IsKeyPressed(KEY_FOUR)) sudoku->setCell(selectedRow, selectedCol, 4);
    if (IsKeyPressed(KEY_FIVE)) sudoku->setCell(selectedRow, selectedCol, 5);
    if (IsKeyPressed(KEY_SIX)) sudoku->setCell(selectedRow, selectedCol, 6);
    if (IsKeyPressed(KEY_SEVEN)) sudoku->setCell(selectedRow, selectedCol, 7);
    if (IsKeyPressed(KEY_EIGHT)) sudoku->setCell(selectedRow, selectedCol, 8);
    if (IsKeyPressed(KEY_NINE)) sudoku->setCell(selectedRow, selectedCol, 9);
}

