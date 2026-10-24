# Experiment 01: Exhaustive Search

## Aim
To implement the exhaustive search technique to solve the Subset Sum problem by systematically examining every possible subset of a given set of positive integers.

## Problem Statement
Given `N` positive integers and a target sum, identify all subsets whose elements add up to the target.

The program represents each subset using a bitmask. Every bit indicates whether the corresponding element is included in the subset. By examining all possible bitmasks, the algorithm checks all \(2^N\) subsets.

## Algorithm
1. Read the number of elements, the positive integers, and the target sum.
2. Calculate the total number of possible subsets as \(2^N\).
3. Iterate through every bitmask from `0` to \(2^N-1\).
4. For each bitmask, examine every element.
5. If the corresponding bit is set, include that element in the current subset and add its value to the subset sum.
6. Compare the calculated sum with the target.
7. If the sums match, record the subset as a solution.
8. Display the total number of subsets examined and the number of matching subsets.

## Sample Input
```text
4
3 4 5 2
7
```

## Sample Output
```text
Exhaustive Search Results:
Checking subset: { }
Checking subset: { 3 }
Checking subset: { 4 }
Checking subset: { 3 4 } -> Match
...
Checking subset: { 5 2 } -> Match
...

Total subsets checked: 16
Total matching subsets: 2
```

*Note: The output above is abbreviated. The actual program displays all 16 subsets, including their matching status.*

## Test Cases

| Test Case | Elements | Target | Expected Matches |
|---|---|---:|---|
| Multiple solutions | 3, 4, 5, 2 | 7 | 2 |
| No solution | 2, 4, 6 | 5 | 0 |
| Zero target | 1, 2, 3 | 0 | 1, the empty subset |

## Complexity Analysis

- **Time Complexity:** \(O(N \cdot 2^N)\), because the algorithm examines \(2^N\) subsets and processes up to \(N\) elements for each subset.
- **Auxiliary Space Complexity:** \(O(1)\) for the subset enumeration itself, excluding the input array and output.

## Concepts Used
- Exhaustive search
- Bitmask representation
- Subset enumeration
- Bitwise operations
- Combinatorial optimization

## Conclusion
The experiment demonstrates exhaustive search by evaluating every possible subset and identifying those that satisfy the target sum. The method is straightforward and guarantees that no possible subset is skipped, but its exponential growth makes it impractical for large inputs.
