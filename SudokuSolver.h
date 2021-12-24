#ifndef _SUDOKUSOLVER_
#define _SUDOKUSOLVER_
#include <iostream>
#include <tuple>
#include <vector>

using Grid = std::vector<std::vector<int>>;

class SudokuSolver {
    Grid grid;
    std::vector<std::tuple<int, int>> positions;

   private:
    bool isSafe(Grid grid, int row, int col, int num);
    void shufflePositions();

   public:
    SudokuSolver();
    Grid& getGrid();
    bool solve(Grid& grid, int row, int col);
    int solutionCount(Grid grid, int row, int col, int count);
    bool initGrid(Grid& grid, int row, int col);
    void printResult(Grid grid);
    void reduce(Grid& grid);
};
#endif
