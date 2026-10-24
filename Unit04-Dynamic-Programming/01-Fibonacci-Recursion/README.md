# Experiment 01: Fibonacci Using Recursion

## Aim
To implement a recursive algorithm in C++ to calculate the Fibonacci number at a given position.

## Objectives
- Understand the Fibonacci sequence.
- Implement recursion using a function.
- Identify base cases and recursive cases.
- Analyze the time and space complexity of recursive Fibonacci.
- Understand the limitations of repeated recursive calculations.

## Problem Statement
Given a non-negative integer `n`, calculate the Fibonacci number at position `n` using recursion.

The Fibonacci sequence begins with `0, 1, 1, 2, 3, 5, 8, 13, ...`. Each number after the first two is the sum of the preceding two numbers.

## Theory
Recursion is a programming technique in which a function calls itself to solve smaller instances of a problem.

The Fibonacci sequence is defined as:

\[
F(n)=
\begin{cases}
0 & n=0\\
1 & n=1\\
F(n-1)+F(n-2) & n\geq2
\end{cases}
\]

The recursive implementation uses two base cases:
- If `n` is `0`, return `0`.
- If `n` is `1`, return `1`.

For other values, the function returns the sum of `fibonacci(n - 1)` and `fibonacci(n - 2)`.

## Algorithm
1. Start the program.
2. Read the Fibonacci position `n`.
3. Validate that `n` is between 0 and 40.
4. If `n` is 0 or 1, return `n`.
5. Otherwise, recursively calculate `fibonacci(n - 1) + fibonacci(n - 2)`.
6. Display the resulting Fibonacci number.
7. End the program.

## Pseudocode
```text
FUNCTION Fibonacci(n)
    IF n <= 1
        RETURN n
    END IF

    RETURN Fibonacci(n - 1) + Fibonacci(n - 2)
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
```text
Enter the Fibonacci position (0-40): 10
```

## Sample Output
```text
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
The naive recursive implementation repeatedly calculates the same Fibonacci values. Its time complexity has an exponential upper bound of **O(2ⁿ)**.

### Space Complexity
The maximum depth of the recursive call stack is proportional to `n`, giving an auxiliary space complexity of **O(n)**.

## Limitations
- Repeated calculations make this implementation inefficient for large values of `n`.
- The program restricts input to the range 0 to 40 to keep execution time manageable.
- Recursion introduces function-call overhead.

## Learning Outcomes
- Understood the concept of recursion.
- Implemented base cases and recursive function calls in C++.
- Applied a recursive definition to calculate Fibonacci numbers.
- Analyzed the time and space complexity of a recursive algorithm.
- Identified redundant calculations that can be improved using memoization.

## Conclusion
The Fibonacci sequence was successfully implemented in C++ using recursion. The experiment demonstrates how a problem can be broken into smaller subproblems, while also revealing the inefficiency caused by repeated calculations. Memoization will be explored in the next experiment to improve performance.
