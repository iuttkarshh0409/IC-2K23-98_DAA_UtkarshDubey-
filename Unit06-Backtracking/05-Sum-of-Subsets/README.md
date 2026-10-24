# Experiment 05: Sum of Subsets

## Aim
To implement the Sum of Subsets problem using backtracking and find all subsets of a given set of positive integers whose sum equals a specified target.

## Problem Statement
Given `N` positive integers and a target sum, find and display every subset whose elements add up to the target.

The program explores two choices for each element: include it in the current subset or exclude it. It uses fixed-size arrays and supports up to 20 elements.

## Algorithm
1. Read the number of elements, the positive integers, and the target sum.
2. Start the recursive search at the first element with a current sum of zero.
3. Include the current element in the selected subset and recursively explore the remaining elements.
4. Backtrack and explore the alternative by excluding the current element.
5. When all elements have been considered, check whether the current sum equals the target.
6. If the sums match, print the subset and increment the solution count.
7. After exploring all possibilities, display the total number of valid subsets or report that no subset was found.

## Sample Input
```text
4
3 4 5 2
7
```

## Sample Output
```text
Enter number of elements (1-20): 4
Enter positive integers:
Enter target sum: 7

Subsets with sum 7:
{ 3 4 }
{ 5 2 }

Total subsets found: 2
```

## Test Cases

| Test Case | Input Elements | Target | Expected Result |
|---|---|---:|---|
| Multiple solutions | 3, 4, 5, 2 | 7 | `{3, 4}` and `{5, 2}` |
| No solution | 2, 4, 6 | 5 | No subset found |
| Zero target | 1, 2, 3 | 0 | Empty subset |
| Single-element solution | 7 | 7 | `{7}` |

## Complexity Analysis

- **Time Complexity:** \(O(2^N)\) for exploring all possible subsets, excluding the additional cost of printing solutions.
- **Auxiliary Space Complexity:** \(O(N)\) for the recursion stack and the array storing selected elements.

## Concepts Used
- Backtracking
- Recursion
- Fixed-size arrays
- Include/exclude decisions
- Subset enumeration

## Conclusion
The Sum of Subsets problem demonstrates how backtracking systematically explores all possible combinations by including or excluding each element. It identifies every subset that satisfies the target sum and counts the valid solutions.
