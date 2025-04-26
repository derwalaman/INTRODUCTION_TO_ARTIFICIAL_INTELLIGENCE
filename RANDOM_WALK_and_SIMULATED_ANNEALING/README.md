# 8-Queens Problem Solver

## 🏁 Aim

Using a standard chessboard of dimensions **8×8** and eight identical queens, the goal is to strategically place all the queens such that:
- No two queens threaten each other.
- No two queens are in the same **row**, **column**, or **diagonal**.

This project implements two methods to find a conflict-free configuration:
- **Case 1**: Random Walk Search
- **Case 2**: Simulated Annealing Search

---

## 📁 File Structure
```bash 
RANDOM_WALK_and_SIMULATED_ANNEALING/
│
├── main.cpp            # C++ implementation
├── README.md           # Project documentation (you are here)
```

---

## 📋 Problem Statement

- **Start**: Initial random placement of 8 queens on the board.
- **Goal**: Move queens iteratively to reach a configuration with **zero conflicts**.
- **Constraints**:
  - Only one queen per row.
  - Only one queen per column.
  - No two queens on the same diagonal.

---

## ⚙️ Approaches Used

### 1. Random Walk Approach
- At each step, randomly select a queen.
- Move it to a position within its row that reduces the total number of conflicts.
- Repeat until a conflict-free board is found or the maximum number of steps is reached.

### 2. Simulated Annealing Approach
- Begin with a high "temperature" and gradually cool down.
- At each step:
  - Randomly pick a queen and a new column.
  - Accept worse moves with a probability depending on the temperature (to escape local minima).
  - Gradually reduce the temperature to minimize randomness over time.
- Success when a zero-conflict board is found.

---

## 🧙‍♂️ Code Structure

- `calculateConflicts(board)`: Counts how many pairs of queens are attacking each other.
- `solveRandomWalk(board)`: Attempts to solve using the Random Walk approach.
- `solveSimulatedAnnealing(board)`: Attempts to solve using the Simulated Annealing approach.
- `printBoard(board)`: Nicely prints the chessboard with queens (`Q`) and empty spots (`.`).

---

## 💻 How to Run

1. Make sure you have a C++ compiler installed (like `g++`).
2. Save the provided code in a file named `eight_queens.cpp`.
3. Open a terminal and run:
   ```bash
   g++ eight_queens.cpp -o eight_queens
   ./eight_queens
   ```

4. You will see outputs for both the **Random Walk** and **Simulated Annealing** methods.

---

## 📈 Example Output

```bash
Random Walk Approach:
✅ Solution found!
. . . . Q . . .
Q . . . . . . .
. . . . . Q . .
. . . Q . . . .
. . . . . . Q .
. Q . . . . . .
. . . . . . . Q
. . Q . . . . .

Simulated Annealing Approach:
✅ Solution found!
. . . Q . . . .
Q . . . . . . .
. . . . . Q . .
. . . . . . . Q
. Q . . . . . .
. . . . Q . . .
. . . . . . Q .
. . Q . . . . .
```

---

## 🚀 Notes
- Random Walk might get stuck and fail sometimes (especially if the maximum steps are too low).
- Simulated Annealing is generally more reliable because it can accept uphill moves temporarily.
- The random starting configuration is different each time you run the program.

---
