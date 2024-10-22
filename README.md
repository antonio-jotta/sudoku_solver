# Sudoku Solver

This project is a C++ implementation of a **Sudoku Solver** using the **Backtracking** algorithm with recursion. The program allows you to solve a standard 9x9 Sudoku puzzle where empty cells are represented by `0`.

## Features

- Solves a 9x9 Sudoku puzzle using backtracking.
- Input grid can be customized by filling in the board in the code.

## How It Works

The solver uses a recursive backtracking algorithm:

1. It starts by filling the grid from the top-left corner, trying numbers from `1` to `9`.
2. It checks whether a number can be legally placed in the current cell (i.e., it does not conflict with the numbers in the same row, column, or 3x3 subgrid).
3. If a valid number is found, it moves on to the next cell.
4. If no valid number can be placed in the current cell, it backtracks to the previous cell and tries the next number.
5. This process continues until the entire grid is filled or it's determined that the puzzle cannot be solved.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/sudoku-solver.git
   cd sudoku-solver

2. Modify the Sudoku board in main.cpp by replacing the grid variable with your own puzzle. Empty spaces should be represented by 0:

    ```cpp
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

3. Compile and run the program:
    ```bash
    g++ main.cpp -o sudoku_solver
    ./sudoku_solver

4. The program will print the solved Sudoku grid to the console if a solution exists, or it will indicate that the puzzle is unsolvable, and will print the time it took for the solving algorithm to run.

## Example Output
Given the following input:

    5 3 0 0 7 0 0 0 0
    6 0 0 1 9 5 0 0 0
    0 9 8 0 0 0 0 6 0
    8 0 0 0 6 0 0 0 3
    4 0 0 8 0 3 0 0 1
    7 0 0 0 2 0 0 0 6
    0 6 0 0 0 0 2 8 0
    0 0 0 4 1 9 0 0 5
    0 0 0 0 8 0 0 7 9



The output will be:

    5 3 4 6 7 8 9 1 2
    6 7 2 1 9 5 3 4 8
    1 9 8 3 4 2 5 6 7
    8 5 9 7 6 1 4 2 3
    4 2 6 8 5 3 7 9 1
    7 1 3 9 2 4 8 5 6
    9 6 1 5 3 7 2 8 4
    2 8 7 4 1 9 6 3 5
    3 4 5 2 8 6 1 7 9
