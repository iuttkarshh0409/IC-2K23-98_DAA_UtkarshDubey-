# Experiment 02: 4-Queens Problem Using Backtracking

## Aim
To solve the 4-Queens problem using the backtracking technique in C++ and display all valid arrangements of four queens on a chessboard.

## Problem Statement
Place four queens on a \(4 \times 4\) chessboard such that no two queens attack each other. No two queens may share the same row, column, or diagonal. Use backtracking to find and display all valid solutions.

## Theory
The **N-Queens problem** is a classic application of backtracking. A queen can attack other pieces horizontally, vertically, and diagonally.

This implementation places exactly one queen in each row. For every row, it tries each column and checks whether the placement is safe. If a placement leads to a dead end, the algorithm removes the queen and tries another position.

## Algorithm
1. Initialize the \(4 \times 4\) board with zeros.
2. Start placing queens from row zero.
3. For each column in the current row:
   - Check whether the column contains a queen in an earlier row.
   - Check the upper-left diagonal.
   - Check the upper-right diagonal.
4. If the position is safe, place a queen.
5. Recursively solve the next row.
6. Once all four rows contain queens, display the solution.
7. Remove the queen and continue searching for other solutions.
8. Display the total number of solutions found.

## Pseudocode

```text id="7jd4v2"
SOLVE_QUEENS(row)
    if row = N
        increment solution count
        display board
        return

    for col = 0 to N - 1
        if IS_SAFE(row, col)
            board[row][col] = 1
            SOLVE_QUEENS(row + 1)
            board[row][col] = 0

IS_SAFE(row, col)
    check column in previous rows
    check upper-left diagonal
    check upper-right diagonal

    if no attacking queen exists
        return true
    otherwise
        return false
```

## Sample Output

The program finds two valid solutions. The following boards illustrate the two arrangements.

### Solution 1

```text id="d3k1w9"
. Q . .
. . . Q
Q . . .
. . Q .
```

### Solution 2

```text id="x8m4p6"
. . Q .
Q . . .
. . . Q
. Q . .
```

Here, `Q` represents a queen and `.` represents an empty square.

```text id="m9v3t7"
Total solutions found: 2
```

## Complexity Analysis

Let \(N\) represent the number of queens and the dimensions of the chessboard.

| Metric | Complexity |
|---|---|
| Worst-case search time | \(O(N!)\) as a commonly used upper bound for row-by-row search with column restrictions |
| Safety check | \(O(N)\) per attempted placement |
| Board storage | \(O(N^2)\) |
| Recursive call stack | \(O(N)\) |
| Total space complexity | \(O(N^2)\) |

The search explores alternative queen placements and backtracks whenever a placement prevents completion of a valid arrangement.

## Edge Cases
- The algorithm finds no solution for board sizes with no valid arrangement.
- A queen must not share a column with a previously placed queen.
- Diagonal attacks must be checked in both directions above the current row.
- Every completed solution must contain exactly one queen per row.

## Learning Outcomes
- Understood the backtracking approach to constraint-solving problems.
- Implemented recursive search in C++.
- Learned how to validate column and diagonal constraints.
- Applied backtracking to enumerate all valid board arrangements.
- Analyzed search complexity and memory requirements.

## Conclusion
The program successfully solves the 4-Queens problem using backtracking and finds both valid arrangements for a \(4 \times 4\) board. It demonstrates how invalid partial solutions are abandoned by undoing previous placements.
