# Sudoku Solver in C

Welcome to the **Sudoku Solver in C** project! This code will solve any given Sudoku puzzle. It was developed as a homework assignment during my time in school, and it has been completed and submitted successfully.

## Overview

Sudoku is a popular logic-based number placement puzzle. The objective is to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 subgrids contain all of the digits from 1 to 9. This project implements a Sudoku solver in the C programming language, which can solve any valid Sudoku puzzle input.

## Features

- Solves any valid 9x9 Sudoku puzzle.
- Implements a backtracking algorithm to efficiently solve the puzzle.
- Written in C, making it fast and efficient.

## How It Works

The solver uses a backtracking algorithm to fill in the empty cells of the Sudoku grid. It recursively tries numbers from 1 to 9 in each empty cell, and if it finds a valid placement (i.e., the number does not violate Sudoku rules), it moves on to the next cell. If it encounters a cell where no number is valid, it backtracks to the previous cell and tries the next number.

## Usage

### Compilation

To compile the code, you need a C compiler such as `gcc`. Use the following command to compile the code:

```sh
gcc -o sudoku_solver sudoku_solver.c
