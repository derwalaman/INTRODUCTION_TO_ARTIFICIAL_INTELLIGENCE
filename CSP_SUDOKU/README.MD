# 🧩 Sudoku Solver Using CSP (Constraint Satisfaction Problem)

---

## 📋 Project Overview

This project implements a **Sudoku Solver** using **Constraint Satisfaction Problem (CSP)** techniques.  
The solver applies advanced strategies like:

- **Minimum Remaining Value (MRV) Heuristic**: Choose the next empty cell with the fewest valid options.
- **Least Constraining Value (LCV) Heuristic**: Choose the number that least limits possibilities for other empty cells.
- **Backtracking Search**: Systematically explore possible assignments and backtrack when necessary.

The goal is to fill the entire 9×9 Sudoku grid while respecting Sudoku rules.

---

## 🛠️ Features

- Input a Sudoku board manually (0s represent empty cells).
- Uses **MRV**, **LCV**, and **Backtracking** for efficient solving.
- Clean and modular **C++** implementation.
- Prints both the original and solved Sudoku boards.
- Shows step-by-step solving using CSP logic.

---

## 🧠 Concepts Used

### 1. Constraint Satisfaction Problem (CSP)

Sudoku is modeled as a CSP where:

- **Variables**: Each empty cell.
- **Domains**: Digits {1, 2, ..., 9}.
- **Constraints**: No repeated digits in a row, column, or 3×3 box.

### 2. Minimum Remaining Values (MRV)

At each step, select the cell (variable) with the fewest legal moves available (smallest domain size).  
This heuristic speeds up the search by tackling the hardest cells first.

### 3. Least Constraining Value (LCV)

When assigning a number to a cell, prefer numbers that impose the fewest restrictions on neighboring cells.  
This maximizes flexibility for future moves.

### 4. Backtracking Search

If no valid number can be placed in a cell, backtrack to a previous cell and try a different number.

---

## 🧩 How the Solver Works

1. Read or define a partially filled 9×9 Sudoku grid.
2. Find the empty cell with the **minimum remaining values (MRV)**.
3. For that cell, try all possible numbers ordered by **least constraining value (LCV)**.
4. Assign a number and recursively solve the rest of the board.
5. If stuck, **backtrack** and try a different assignment.
6. Continue until all cells are filled correctly.

