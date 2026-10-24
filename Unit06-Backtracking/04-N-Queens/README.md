# Experiment 04: N-Queens Problem

## Aim
To solve the general N-Queens problem using the backtracking technique by placing N queens on an N × N chessboard such that no two queens attack each other.

## Problem Statement
Given an integer `N`, place `N` queens on an `N × N` chessboard so that no two queens share the same row, column, or diagonal. Print all valid arrangements and the total number of solutions.

The program supports values of `N` from 1 to 15.

## Algorithm
1. Initialize an empty `N × N` chessboard.
2. Start placing queens row by row.
3. For each row, try every column.
4. Check whether placing a queen at the current position is safe by examining:
   - The column above the current position.
   - The upper-left diagonal.
   - The upper-right diagonal.
5. If the position is safe, place the queen and recursively process the next row.
6. If all rows contain a queen, print the arrangement and increment the solution count.
7. If a placement leads to no solution, remove the queen and try the next column.
8. Display the total number of solutions after the search finishes.

## Sample Input
```text
4
```

## Sample Output
```text
Enter the value of N (1-15): 4

Solution 1:
. Q . .
. . . Q
Q . . .
. . Q .

Solution 2:
. . Q .
Q . . .
. . . Q
. Q . .

Total solutions found: 2
```

*Note: The board formatting may vary slightly depending on the implementation.*

## Test Cases

| Input N | Expected Number of Solutions |
|---:|---:|
| 1 | 1 |
| 2 | 0 |
| 3 | 0 |
| 4 | 2 |
| 5 | 10 |
| 8 | 92 |

For `N = 2` and `N = 3`, the program reports that no solution exists.

## Complexity Analysis

- **Time Complexity:** Commonly expressed as \(O(N!)\) for row-by-row backtracking with column restrictions, with additional work for safety checks.
- **Space Complexity:** \(O(N^2)\) for the chessboard and \(O(N)\) for the recursion stack.

## Concepts Used
- Backtracking
- Recursion
- Two-dimensional arrays
- Constraint checking
- Combinatorial search

## Conclusion
The N-Queens problem demonstrates how backtracking explores possible placements, rejects invalid configurations early, and systematically finds every valid arrangement for a given board size.
