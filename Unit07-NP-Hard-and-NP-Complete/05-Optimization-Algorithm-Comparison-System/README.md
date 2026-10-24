# Experiment 05: Optimization Algorithm Comparison System

## Aim
To develop an optimization comparison system that evaluates Exhaustive Search and Branch and Bound for solving the 0/1 Knapsack problem.

## Problem Statement
Given a set of items, each with a weight and value, and a knapsack with a fixed capacity, determine the maximum achievable value without exceeding the capacity.

The system implements two optimization approaches:

1. **Exhaustive Search:** Examines every possible subset of items to identify the optimal feasible solution.
2. **Branch and Bound:** Explores include/exclude decisions recursively and prunes branches whose upper bound cannot improve the best solution found so far.

The system compares their optimal values, search effort, and execution times. It also displays the item selection obtained by Branch and Bound.

## Features
- Supports up to 20 items.
- Validates item weights, values, and knapsack capacity.
- Calculates the optimal value using Exhaustive Search.
- Calculates the optimal value using Branch and Bound.
- Measures execution time for both algorithms.
- Counts examined subsets and visited search nodes.
- Displays selected items and their total weight.
- Reports whether both algorithms found the same optimal value.

## Algorithm

### 1. Exhaustive Search
1. Generate all \(2^N\) subsets using bitmasks.
2. Calculate the total weight and value of each subset.
3. Reject subsets that exceed the knapsack capacity.
4. Record the maximum value among feasible subsets.
5. Count the subsets examined and measure execution time.

### 2. Branch and Bound
1. Begin with zero weight and zero value.
2. Recursively explore including or excluding each item.
3. Reject branches that exceed the capacity.
4. Estimate an upper bound by adding all remaining item values to the current value.
5. Prune branches whose upper bound cannot improve the current best value.
6. Store the best feasible item selection.
7. Count visited search nodes and measure execution time.

### 3. Comparison
1. Execute both algorithms using the same input.
2. Display their optimal values, search counts, and execution times.
3. Display the selected items from Branch and Bound.
4. Compare the optimal values and report whether they agree.

## Sample Input
```text
4
2 40
3 50
4 65
5 70
8
```

## Expected Results

| Metric | Exhaustive Search | Branch and Bound |
|---|---|---|
| Maximum value | 120 | 120 |
| Subsets or nodes | 16 subsets | Depends on pruning |
| Execution time | Measured at runtime | Measured at runtime |

The selected items should have a combined weight of `8` and a combined value of `120`.

Execution times and the number of search nodes visited can vary with the input and implementation details.

## Test Cases

| Test Case | Knapsack Capacity | Expected Maximum Value |
|---|---:|---:|
| Standard knapsack | 8 | 120 |
| Zero capacity | 0 | 0 |
| All items fit | 10 | 60 |

Both algorithms should produce the same optimal value for each valid test case.

## Complexity Analysis

- **Exhaustive Search:** \(O(N2^N)\) time, because each subset may require examining all \(N\) items.
- **Branch and Bound:** \(O(N2^N)\) worst-case time in this implementation, since its upper-bound calculation examines the remaining items at each search node.
- **Auxiliary Space:** \(O(N)\) for selection arrays and the recursive search stack.

Branch and Bound may reduce practical search effort by pruning unpromising branches, but the current upper bound is relatively weak because it ignores the weights of remaining items.

## Concepts Used
- 0/1 Knapsack
- Exhaustive search
- Branch and Bound
- Bitmask enumeration
- Recursive search
- Upper-bound estimation
- Branch pruning
- Algorithm comparison
- Runtime measurement

## Limitations
- Supports at most 20 items.
- Uses a simple upper bound that may provide limited pruning.
- Runtime measurements may be unreliable for small inputs because execution is very fast.
- Branch and Bound is not guaranteed to outperform Exhaustive Search on every input.

## Conclusion
The Optimization Algorithm Comparison System demonstrates two approaches to solving the 0/1 Knapsack problem. Exhaustive Search guarantees an optimal solution by examining every subset, while Branch and Bound can reduce search effort by pruning branches that cannot improve the current solution. Comparing their results and performance illustrates the trade-offs between complete enumeration and guided search.
