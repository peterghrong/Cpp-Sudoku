#include "SudokuSolver.h"

#include <algorithm>
#include <random>
#include <vector>

SudokuSolver::SudokuSolver() {
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        std::vector<int> vec;
        for (int j = 0; j < 9; j++) {
            vec.push_back(0);
            positions.push_back(std::make_tuple(i, j));
        }
        grid.push_back(vec);
    }
}

Grid& SudokuSolver::getGrid() {
    return grid;
}

void SudokuSolver::shufflePositions() {
    std::shuffle(positions.begin(), positions.end(), std::random_device());
}

bool SudokuSolver::isSafe(Grid grid, int row,
                          int col, int num) {
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3,
        startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool SudokuSolver::solve(Grid& grid, int row, int col) {
    if (row == 9 - 1 && col == 9)
        return true;

    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solve(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

bool SudokuSolver::initGrid(Grid& grid, int row, int col) {
    if (row == 9 - 1 && col == 9)
        return true;

    if (col == 9) {
        row++;
        col = 0;
    }

    std::vector<int> randInts;
    while (randInts.size() != 9) {
        int randInt = (rand() % 9) + 1;
        // if this randInt has not been used
        if (std::find(randInts.begin(), randInts.end(), randInt) == randInts.end()) {
            randInts.push_back(randInt);

            if (isSafe(grid, row, col, randInt)) {
                grid[row][col] = randInt;
                if (initGrid(grid, row, col + 1))
                    return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void SudokuSolver::printResult(Grid grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            std::cout << grid[i][j] << " ";
        std::cout << std::endl;
    }
}

int SudokuSolver::solutionCount(Grid grid, int row, int col, int count) {
    if (row == 9 - 1 && col == 9)
        return count + 1;

    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solutionCount(grid, row, col + 1, count);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            count = solutionCount(grid, row, col + 1, count);
        }
    }
    grid[row][col] = 0;
    return count;
}

void SudokuSolver::reduce(Grid& grid) {
    shufflePositions();
    for (int i = 0; i < 81; i++) {
        int row = std::get<0>(positions[i]);
        int col = std::get<1>(positions[i]);
        int num = grid[row][col];
        grid[row][col] = 0;
        if (solutionCount(grid, row, col, 0) != 1) {
            grid[row][col] = num;
        }
    }
};

int main() {
    SudokuSolver sudoku = SudokuSolver();
    sudoku.initGrid(sudoku.getGrid(), 0, 0);
    // sudoku.printResult(sudoku.getGrid());

    std::cout << "\n";
    sudoku.reduce(sudoku.getGrid());
    sudoku.printResult(sudoku.getGrid());

    // std::cout << "\n";
    // sudoku.solve(sudoku.getGrid(), 0, 0);
    // sudoku.printResult(sudoku.getGrid());
}