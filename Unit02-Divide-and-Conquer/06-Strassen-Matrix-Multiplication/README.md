# Experiment 06: Strassen's Matrix Multiplication

## Aim
To implement Strassen's matrix multiplication algorithm using the Divide and Conquer technique in C++.

## Problem Statement
Given two square matrices of order \(n \times n\), calculate their product using Strassen's algorithm, which reduces the number of recursive matrix multiplications from eight to seven.

## Objectives
- Understand the Divide and Conquer approach to matrix multiplication.
- Implement Strassen's seven recursive multiplication formulas.
- Handle matrix dimensions that are not powers of two through padding.
- Analyze the time and auxiliary space complexity of the algorithm.

## Theory
Conventional matrix multiplication using the standard method takes \(O(n^3)\) time. Strassen's algorithm divides each matrix into four submatrices and uses seven recursive multiplications instead of eight.

The seven products are:

\[
\begin{aligned}
M_1 &= (A_{11}+A_{22})(B_{11}+B_{22})\\
M_2 &= (A_{21}+A_{22})B_{11}\\
M_3 &= A_{11}(B_{12}-B_{22})\\
M_4 &= A_{22}(B_{21}-B_{11})\\
M_5 &= (A_{11}+A_{12})B_{22}\\
M_6 &= (A_{21}-A_{11})(B_{11}+B_{12})\\
M_7 &= (A_{12}-A_{22})(B_{21}+B_{22})
\end{aligned}
\]

The resulting submatrices are:

\[
\begin{aligned}
C_{11} &= M_1+M_4-M_5+M_7\\
C_{12} &= M_3+M_5\\
C_{21} &= M_2+M_4\\
C_{22} &= M_1-M_2+M_3+M_6
\end{aligned}
\]

For dimensions that are not powers of two, the implementation pads both matrices with zeros to the next power-of-two dimension. After multiplication, it extracts the original \(n \times n\) result.

## Algorithm
1. Read the order \(n\) of the square matrices.
2. Read the elements of matrices A and B.
3. Find the next power of two greater than or equal to \(n\).
4. Pad both matrices with zeros to the required dimension.
5. Divide the matrices into four equal-sized quadrants.
6. Compute the seven Strassen products recursively.
7. Combine the products to construct the four result quadrants.
8. Repeat until the base case of a \(1 \times 1\) matrix is reached.
9. Crop the padded result to the original dimensions.
10. Display the product matrix.

## Pseudocode

```text
STRASSEN(A, B, n)
    if n = 1
        return A[0][0] * B[0][0]

    Divide A and B into four quadrants each

    M1 = STRASSEN(A11 + A22, B11 + B22)
    M2 = STRASSEN(A21 + A22, B11)
    M3 = STRASSEN(A11, B12 - B22)
    M4 = STRASSEN(A22, B21 - B11)
    M5 = STRASSEN(A11 + A12, B22)
    M6 = STRASSEN(A21 - A11, B11 + B12)
    M7 = STRASSEN(A12 - A22, B21 + B22)

    C11 = M1 + M4 - M5 + M7
    C12 = M3 + M5
    C21 = M2 + M4
    C22 = M1 - M2 + M3 + M6

    Combine C11, C12, C21, C22
    return C
```

## Flowchart

```text
Start
  |
Read matrix order and elements
  |
Validate input
  |
Pad matrices to next power of two
  |
Call Strassen multiplication
  |
Is dimension = 1?
  | Yes                 | No
Multiply elements       Divide into quadrants
  |                     |
  |                     Compute M1 to M7
  |                     |
  |                     Combine result quadrants
  |                     |
  +----------<----------+
  |
Crop result to original dimensions
  |
Display product matrix
  |
Stop
```

## Sample Input

```text
2
1 2
3 4
5 6
7 8
```

## Sample Output

```text
Product Matrix (A x B):
19 22
43 50
```

## Complexity Analysis

The recurrence relation is:

\[
T(n)=7T(n/2)+\Theta(n^2)
\]

By the Master Theorem:

\[
T(n)=\Theta(n^{\log_2 7})
\approx \Theta(n^{2.807})
\]

| Case | Time Complexity |
|---|---|
| Best | \(\Theta(n^{2.807})\) |
| Average | \(\Theta(n^{2.807})\) |
| Worst | \(\Theta(n^{2.807})\) |

- **Auxiliary space:** \(O(n^2)\) for this recursive implementation's live matrix storage, with a substantial constant-factor overhead from temporary matrices.
- **Conventional matrix multiplication:** \(O(n^3)\) time.

These bounds assume arithmetic operations have constant cost and ignore integer overflow.

## Test Cases

| Test | Input condition | Expected result |
|---|---|---|
| 1 | \(2 \times 2\) matrices | Correct product matrix |
| 2 | \(1 \times 1\) matrices | Product of the two elements |
| 3 | \(3 \times 3\) matrices | Correct product after padding |
| 4 | Invalid dimension \(n=0\) | Error message and program termination |

All listed test cases were executed successfully.

## Source File
`src/main.cpp`

## Learning Outcomes
- Understood Strassen's Divide and Conquer strategy.
- Implemented matrix addition, subtraction, quadrant extraction, and recombination.
- Applied recursive multiplication using seven products.
- Handled non-power-of-two matrix dimensions using zero padding.
- Analyzed the recurrence relation and asymptotic time complexity.

## Conclusion
Strassen's matrix multiplication was implemented and tested successfully in C++. The algorithm reduces the asymptotic multiplication time to approximately \(\Theta(n^{2.807})\), at the cost of additional matrix operations and temporary storage.
