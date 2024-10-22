#include <iostream>
#include <chrono> 
#define N 9

void print_grid(int grid[N][N]);
bool compare_grids(int solution[N][N], int ground_truth[N][N]);
bool is_valid(int grid[N][N], int r, int c, int k);
bool solve(int grid[N][N], int r, int c);

int main()
{
    int grid[N][N] = {
        {9, 0, 4, 0, 0, 5, 6, 0, 0},
        {0, 0, 0, 4, 9, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 8, 0, 4, 0},
        {0, 3, 2, 9, 0, 4, 0, 0, 0},
        {7, 0, 5, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 2, 8, 0},
        {5, 6, 1, 7, 0, 0, 0, 0, 8},
        {0, 0, 0, 8, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 9, 0, 1, 5}};


    std::cout << "**SUDOKU SOLVER**\n\n";
    
    std::cout << "**INITIAL  GRID**\n\n";
    print_grid(grid);
    
    // Timer to measure the time it took to solve the puzzle
    auto start = std::chrono::high_resolution_clock::now();
    
    bool status = solve(grid, 0, 0);
    
    auto end = std::chrono::high_resolution_clock::now();
    
    if(status == false){
        std::cout << "***NO SOLUTION***\n\n";
    }
    else{
        std::cout << "*****SOLUTION****\n\n";
        print_grid(grid);

        // Calculate the duration
        std::chrono::duration<double> duration = end - start;
        std::cout << "Time taken to solve: " << duration.count() << " seconds\n\n";

    }

    std::cout << "*****************\n";

    return 0;
}

bool solve(int grid[N][N], int r, int c)
{
    // If we reach the end of the row, move to the next row
    if(c == N)
    {
        c = 0; 
        r++;

        // If we reach the last row, the puzzle is solved
        if(r == N)
        {
            return true; // Puzzle solved
        }
    }

    // If the current cell is already filled, move to the next cell
    if(grid[r][c] != 0)
    {
        return solve(grid, r, c+1);
    }

    // Try every number between 1 and 9
    for(int i = 1; i <= 9; i++)
    {
        if(is_valid(grid, r, c, i))
        {
            grid[r][c] = i; // Place the value

            // Recursively solve the next cell
            if(solve(grid, r, c+1))
            {
                return true; // If it's solvable, return true
            }

            grid[r][c] = 0; // Reset the cell (backtrack)
        }
    }

    return false; // Trigger backtracking if no number works
}


bool is_valid(int grid[N][N], int r, int c, int k)
{
    if(grid[r][c] != 0) return false;

    int grid_x = (c/3)*3;
    int grid_y = (r/3)*3;


    //Check if k exists in the collumn and the row
    for(int i = 0; i < N; i++)
    {
        if(grid[r][i] == k) return false;
        if(grid[i][c] == k) return false;
        if(grid[grid_y + i/3][grid_x + i%3] == k) return false;
    }

    return true;
}

bool compare_grids(int solution[N][N], int ground_truth[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(solution[i][j] != ground_truth[i][j]) return false;
        }
    }

    return true;
}

void print_grid(int grid[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}