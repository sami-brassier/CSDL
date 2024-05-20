#ifndef SUDOKU_HPP
#define SUDOKU_HPP

// Sudoku class represents the Sudoku puzzle and handles its logic
class Sudoku {
public:
    Sudoku();  // Constructor to initialize the Sudoku grid
    int getCell(int row, int col) const;  // Get the value of a cell
    void setCell(int row, int col, int num);  // Set the value of a cell

private:
    int grid[9][9];  // 2D array representing the Sudoku grid

    bool isValid(int row, int col, int num) const;  // Check if placing a number is valid
    void initializeGrid();  // Initialize the Sudoku grid with some values
};

#endif // SUDOKU_HPP
