# Experiment 02: 0/1 Knapsack Using Branch and Bound

## Aim
To implement the 0/1 Knapsack problem using the Branch and Bound technique to maximize the total value of selected items without exceeding the knapsack's capacity.

## Problem Statement
Given `N` items, each with a weight and value, and a knapsack with a specified capacity, determine the subset of items that produces the maximum total value while keeping the total weight within the capacity.

Each item must either be selected completely or excluded. Fractional selection of items is not permitted in the final solution.

The program supports up to 20 items.

## Algorithm
1. Read the number of items, their weights and values, and the knapsack capacity.
2. Calculate the value-to-weight ratio for each item.
3. Sort the items in descending order of their value-to-weight ratios.
4. Start the recursive search with zero weight and zero value.
5. At each node, calculate an upper bound on the maximum achievable value using a fractional relaxation of the remaining items.
6. If the current weight exceeds the capacity, discard the branch.
7. If the upper bound cannot improve the best solution found so far, prune the branch.
8. Otherwise, explore two possibilities:
   - Include the current item.
   - Exclude the current item.
9. Record the best feasible selection found during the search.
10. Display the maximum value, selected items, and total weight.

## Sample Input
```text
4
2 40
3 50
4 65
5 70
8
```

## Expected Result
```text
Maximum value: 120
Selected items (in sorted order):
Weight: 5, Value: 70
Weight: 3, Value: 50
Total weight: 8
```

*Note: The selected-item display order depends on the sorting implementation. The optimal total value is 120, with total weight 8.*

## Test Cases

| Test Case | Capacity | Expected Maximum Value |
|---|---:|---:|
| Standard knapsack | 8 | 120 |
| Zero capacity | 0 | 0 |
| All items fit | 10 | 60 |

## Complexity Analysis

- **Sorting:** \(O(N^2)\), using bubble sort.
- **Worst-case search time:** \(O(N2^N)\), accounting for recursive exploration and upper-bound calculations.
- **Auxiliary space:** \(O(N)\) for the arrays and recursion stack.

Branch and Bound can reduce the search space substantially when its upper bounds prune many branches. However, its worst-case running time remains exponential.

## Concepts Used
- 0/1 Knapsack
- Branch and Bound
- Recursive state-space exploration
- Upper-bound estimation
- Branch pruning
- Greedy ordering by value-to-weight ratio

## Conclusion
The experiment demonstrates how Branch and Bound improves practical search efficiency by eliminating branches that cannot produce a better solution. The fractional relaxation provides an upper bound, while the final solution continues to respect the indivisible nature of 0/1 items.
