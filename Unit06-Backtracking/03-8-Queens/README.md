# Experiment 03: 8-Queens Problem Using Backtracking

## Aim
To solve the 8-Queens problem using the backtracking technique in C++ and display all valid arrangements of eight queens on an \(8 \times 8\) chessboard.

## Problem Statement
Place eight queens on an \(8 \times 8\) chessboard such that no two queens attack each other. No two queens may share the same row, column, or diagonal. Use backtracking to find and display every valid arrangement.

## Theory
The 8-Queens problem is a classic constraint-satisfaction problem solved using **backtracking**.

The algorithm places one queen in each row. For each row, it examines every column and checks whether the position is safe relative to queens already placed in earlier rows.

If a position is safe, the algorithm places a queen and recursively explores the next row. When a placement prevents a complete solution, the algorithm removes the queen and tries another column.

## Algorithm
1. Initialize an \(8 \times 8\) board with zeros.
2. Begin placing queens from the first row.
3. For each column in the current row:
   - Check the column for previously placed queens.
   - Check the upper-left diagonal.
   - Check the upper-right diagonal.
4. If the position is safe, place a queen.
5. Recursively process the next row.
6. When all eight rows contain queens, increment the solution counter and display the board.
7. Remove the queen to backtrack and explore other positions.
8. Display the total number of solutions after the search finishes.

## Pseudocode

```text id="t3v7k2"
SOLVE_QUEENS(row)
    if row = N
        increment solutionCount
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

MAIN
    SOLVE_QUEENS(0)
    display solutionCount
```

## Expected Result

The program finds **92 valid solutions**, counting rotations and reflections as distinct board arrangements.

```text id="v8k1m4"
Solutions for the 8-Queens Problem:

Solution 1:
[8 × 8 board displayed]

...

Total solutions found: 92
```

The program prints the actual board for every solution. The abbreviated output above illustrates the overall format rather than the complete terminal output.

Here, `Q` represents a queen and `.` represents an empty square.

## Complexity Analysis

Let \(N\) represent the number of queens and the dimensions of the board.

| Metric | Complexity |
|---|---|
| Worst-case search time | \(O(N!)\) as a commonly used upper bound for row-by-row search with column restrictions |
| Safety check | \(O(N)\) per attempted placement |
| Board storage | \(O(N^2)\) |
| Recursion stack | \(O(N)\) |
| Total space complexity | \(O(N^2)\) |

Backtracking avoids exploring every complete board arrangement by rejecting unsafe partial placements early.

## Edge Cases
- The algorithm must reject any placement that shares a column with an existing queen.
- Both diagonal directions must be checked.
- Every completed arrangement must contain exactly eight queens.
- Every valid solution must have exactly one queen per row.
- The solution counter must account for every valid arrangement found.

## Learning Outcomes
- Applied backtracking to a larger constraint-satisfaction problem.
- Implemented recursive search and state restoration in C++.
- Understood column and diagonal constraints.
- Learned how pruning invalid partial arrangements reduces unnecessary exploration.
- Verified the known solution count for the 8-Queens problem.

## Conclusion
The program solves the 8-Queens problem using backtracking and identifies all 92 valid arrangements. It demonstrates how recursive search and undoing previous choices can solve a combinatorial problem efficiently compared with checking every possible board arrangement.
