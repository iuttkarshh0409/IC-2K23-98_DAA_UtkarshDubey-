# Comparative Analysis: Greedy Method vs Dynamic Programming

## 1. Objective

To study and compare the Greedy Method and Dynamic Programming using Fractional Knapsack and 0/1 Knapsack, focusing on their strategies, optimality, time complexity, and space complexity.

## 2. Algorithms Selected

**Fractional Knapsack (Unit 03):** Items can be divided into fractions. The algorithm sorts items by value-to-weight ratio and selects the most valuable available portions first.

**0/1 Knapsack (Unit 04):** Items cannot be divided. Each item must be either selected completely or excluded. Dynamic programming evaluates these possibilities and stores optimal subproblem results.

## 3. Theoretical Comparison

| Parameter | Greedy Method | Dynamic Programming |
|---|---|---|
| Strategy | Locally optimal decisions | Solves overlapping subproblems |
| Decision process | Usually commits to choices | Compares alternatives |
| Main property | Greedy-choice property | Optimal substructure |
| Repeated subproblems | Not necessarily used | Results stored and reused |
| Example | Fractional Knapsack | 0/1 Knapsack |
| Time complexity | O(n log n) with sorting | O(nW) |
| Space complexity | O(1) auxiliary with in-place sorting | O(nW) for a 2D table |
| Optimality | Guaranteed for Fractional Knapsack | Guaranteed for 0/1 Knapsack |

Here, n is the number of items and W is the knapsack capacity. The Greedy complexity assumes an in-place sorting implementation with constant auxiliary space; the exact space usage depends on the sorting algorithm.

## 4. Example

Consider three items:

| Item | Value | Weight | Value/Weight |
|---|---:|---:|---:|
| 1 | 60 | 10 | 6 |
| 2 | 100 | 20 | 5 |
| 3 | 120 | 30 | 4 |

Knapsack capacity = 50.

### 4.1 Fractional Knapsack

The greedy algorithm selects:
- Item 1 completely: value 60, weight 10.
- Item 2 completely: value 100, weight 20.
- Two-thirds of Item 3: value 80, weight 20.

**Maximum value = 240**

### 4.2 0/1 Knapsack

Dynamic programming selects:
- Item 2 completely: value 100, weight 20.
- Item 3 completely: value 120, weight 30.

**Maximum value = 220**

The values differ because Fractional Knapsack permits dividing items, whereas 0/1 Knapsack does not. This is not evidence that the greedy method is inherently superior.

## 5. Why Greedy Does Not Always Work for 0/1 Knapsack

Consider capacity 50 and the same three items.

A greedy strategy based on value-to-weight ratio selects Item 1 and Item 2, obtaining a total value of 160. It cannot fit Item 3 afterward.

However, the optimal 0/1 solution selects Items 2 and 3 for a value of 220.

Therefore, a locally optimal selection strategy does not necessarily produce a globally optimal 0/1 Knapsack solution.

## 6. Complexity Analysis

### Greedy Fractional Knapsack

- Sorting items: O(n log n).
- Selecting items: O(n).
- Total time complexity: O(n log n).
- Auxiliary space depends on the sorting implementation.

### Dynamic Programming 0/1 Knapsack

- Each item is evaluated against capacities from 0 to W.
- Time complexity: O(nW).
- Space complexity: O(nW) for the implemented 2D DP table.

The DP algorithm has pseudo-polynomial time complexity because its running time depends on the numeric capacity W, not only the length of its binary representation.

## 7. Conclusion

The Greedy Method and Dynamic Programming are both important algorithm-design techniques, but their suitability depends on the structure of the problem.

Greedy algorithms are often simpler and efficient when locally optimal choices can be proven to lead to a globally optimal solution. Dynamic programming is useful when a problem exhibits optimal substructure and overlapping subproblems.

Fractional Knapsack is optimally solved using a greedy strategy, while 0/1 Knapsack can be optimally solved using dynamic programming.

## 8. Learning Outcomes

- Understood the difference between greedy choices and dynamic programming.
- Compared Fractional and 0/1 Knapsack.
- Identified why greedy selection can fail for 0/1 Knapsack.
- Analyzed time and space complexity.
- Understood pseudo-polynomial complexity.
- Recognized that algorithm selection depends on problem constraints and mathematical properties.
