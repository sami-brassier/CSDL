#include "Sudoku.hpp"
#include <cstdlib>
#include <ctime>

// Constructor for the Sudoku class
Sudoku::Sudoku() {
    std::srand(std::time(nullptr));  // Seed the random number generator
    initializeGrid();  // Initialize the Sudoku grid
}

// Get the value of the cell at the specified row and column
int Sudoku::getCell(int row, int col) const {
    return grid[row][col];
}

// Set the value of the cell at the specified row and column if valid
void Sudoku::setCell(int row, int col, int num) {
    if (isValid(row, col, num)) {
        grid[row][col] = num;
    }
}

// Check if placing a number in the specified cell is valid
bool Sudoku::isValid(int row, int col, int num) const {
    // Check the row and column for duplicate values
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    // Check the 3x3 subgrid for duplicate values
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Initialize the Sudoku grid with zeros and some random values
void Sudoku::initializeGrid() {
    // Set all cells to zero (empty)
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            grid[i][j] = 0;
        }
    }

    // Randomly populate some cells with valid numbers
    for (int i = 0;  i < 20; ++i) {
        int row = std::rand() % 9;
        int col = std::rand() % 9;
        int num = (std::rand() % 9) + 1;
        if (isValid(row, col, num)) {
            grid[row][col] = num;
        }
    }
}
