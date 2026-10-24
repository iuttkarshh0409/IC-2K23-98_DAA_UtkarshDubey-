# Experiment 02: Fibonacci Using Memoization

## Aim
To implement the Fibonacci sequence using recursion with memoization in C++ and improve efficiency by storing previously calculated results.

## Objectives
- Understand the concept of Dynamic Programming.
- Implement memoization using fixed-size arrays.
- Avoid redundant recursive calculations.
- Compare recursive Fibonacci with memoized Fibonacci.
- Analyze the time and space complexity of the algorithm.

## Problem Statement
Given a non-negative integer `n`, calculate the Fibonacci number at position `n` using memoization.

The Fibonacci sequence begins with `0, 1, 1, 2, 3, 5, 8, 13, ...`. Each number after the first two is the sum of the two preceding numbers.

## Theory
Memoization is a top-down Dynamic Programming technique that stores the results of previously solved subproblems.

The Fibonacci sequence is defined as:

\[
F(n)=
\begin{cases}
0 & n=0\\
1 & n=1\\
F(n-1)+F(n-2) & n\geq2
\end{cases}
\]

In ordinary recursion, the same Fibonacci values may be calculated many times. Memoization avoids this repeated work by storing each calculated result.

The implementation uses two fixed-size arrays:
- `memo[]`: stores calculated Fibonacci numbers.
- `calculated[]`: indicates whether a Fibonacci number has already been calculated.

When a previously calculated value is requested, the function returns the stored result instead of recalculating it.

## Algorithm
1. Initialize the memoization arrays.
2. Read the Fibonacci position `n`.
3. Validate that `n` is between 0 and 40.
4. If `n` is 0 or 1, return `n`.
5. If the result for `n` is already stored, return it.
6. Otherwise, recursively calculate `fibonacci(n - 1)` and `fibonacci(n - 2)`.
7. Store their sum in `memo[n]`.
8. Mark the result as calculated.
9. Return and display the Fibonacci number.

## Pseudocode
```text id="a0kq0f"
FUNCTION Fibonacci(n)
    IF n <= 1
        RETURN n
    END IF

    IF calculated[n] = TRUE
        RETURN memo[n]
    END IF

    memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2)
    calculated[n] = TRUE

    RETURN memo[n]
END FUNCTION

BEGIN
    INPUT n

    IF input is invalid OR n < 0 OR n > 40
        DISPLAY error message
        STOP
    END IF

    result = Fibonacci(n)
    DISPLAY result
END
```

## Sample Input
```text id="gn0qre"
Enter the Fibonacci position (0-40): 10
```

## Sample Output
```text id="zvpg6j"
Fibonacci number at position 10 is 55
```

## Test Cases

| Input position | Expected result |
|---:|---:|
| 0 | 0 |
| 1 | 1 |
| 2 | 1 |
| 7 | 13 |
| 10 | 55 |
| 40 | 102334155 |

Additional validation tests:
- Negative input is rejected.
- Input greater than 40 is rejected.
- Non-integer input is rejected.

## Complexity Analysis

### Time Complexity
Each Fibonacci position is calculated at most once. Therefore, the time complexity is **O(n)**.

### Space Complexity
The memoization arrays require O(n) space for the relevant positions, and the recursive call stack requires O(n) space.

The auxiliary space complexity is **O(n)**.

## Comparison with Ordinary Recursion

| Property | Recursive Fibonacci | Memoized Fibonacci |
|---|---|---|
| Technique | Recursion | Top-down Dynamic Programming |
| Time complexity | O(2ⁿ) upper bound | O(n) |
| Auxiliary space | O(n) | O(n) |
| Repeated calculations | Many | Avoided |
| Result storage | None | Memoization array |

Memoization substantially reduces execution time by storing and reusing previously calculated results.

## Limitations
- The implementation supports Fibonacci positions from 0 to 40.
- Recursion still introduces function-call overhead.
- Fixed-size arrays limit the supported input range.

## Learning Outcomes
- Understood top-down Dynamic Programming.
- Implemented memoization using fixed-size arrays.
- Eliminated redundant recursive calculations.
- Compared recursive and memoized approaches.
- Analyzed time and space complexity.

## Conclusion
The Fibonacci sequence was successfully implemented in C++ using memoization. By storing previously calculated values, the algorithm reduces the time complexity from exponential to linear while preserving the recursive structure.
