# Sudoku Generator in C++

## Introduction
Sudoku solving is a known NP-Complete problem, the only approach to solving this problem is through brute force checking. It turns out that solving a sudoku board is actually the easier part, constructing a unique Sudoku board is slightly more nuanced. I have provided the source code here. What actually happens under the hood is that we construct a random Sudoku board, then remove as many elements as possible for the underlying Sudoku board to still have a unique solution.

## How to run the program
```
git clone git@github.com:peterghrong/Cpp-Sudoku.git
make
./sudoku
```

## Example Sudoku board generated
<p align="center">
  <img src="https://user-images.githubusercontent.com/66083521/147315386-225ab64f-8753-4896-89b9-8d67bc3f22ac.png" alt="hehehe">
</p>

## Inspiration
This [StackOverflow article](https://stackoverflow.com/questions/6924216/how-to-generate-sudoku-boards-with-unique-solutions) outlining the logics for the Sudoku board generation algorithm.

## Todos
1. Code cleanup, a lot of functions here should not be public for the sake of good design.
2. Implementing Sudoku board generation with pre-defined difficulty levels, this is tricky as well because again Sudoku is a NP-Complete problem. Some directions: [this article](https://stackoverflow.com/questions/10488719/generating-a-sudoku-of-a-desired-difficulty)
3. Implementing I/O, where a valid Sudoku board should be outputed as a media file.
4. PROVING THE NP-COMPLETENESS OF SUDOKU.
