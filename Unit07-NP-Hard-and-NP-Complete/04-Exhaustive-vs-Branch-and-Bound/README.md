# Experiment 04: Exhaustive Search vs. Branch and Bound

## Aim
To compare Exhaustive Search and Branch and Bound for solving the 0/1 Knapsack problem in terms of optimal value, search effort, and execution time.

## Problem Statement
Given `N` items, each with a weight and value, and a knapsack capacity, determine the maximum total value obtainable without exceeding the capacity.

The experiment implements two approaches:

1. **Exhaustive Search:** Examines every possible subset of items and selects the best feasible solution.
2. **Branch and Bound:** Explores include/exclude decisions recursively and prunes branches when an upper bound indicates they cannot improve the current best solution.

Both approaches use the same input so their results can be compared fairly.

## Algorithm

### Exhaustive Search
1. Generate all \(2^N\) possible subsets using bitmasks.
2. Calculate the total weight and value of each subset.
3. Reject subsets whose total weight exceeds the capacity.
4. Record the highest value among feasible subsets.
5. Count the subsets examined and measure execution time.

### Branch and Bound
1. Start with zero weight and zero value.
2. Recursively explore including or excluding each item.
3. Reject branches that exceed the knapsack capacity.
4. Calculate an upper bound by adding the values of all remaining items to the current value.
5. Prune a branch if its upper bound cannot improve the best value found.
6. Record the best feasible value, count visited search nodes, and measure execution time.

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
| Search effort | 16 subsets | Number of visited nodes depends on pruning |
| Execution time | Measured at runtime | Measured at runtime |

Both approaches should find the optimal value of `120`.

## Test Cases

| Test Case | Capacity | Expected Maximum Value |
|---|---:|---:|
| Standard knapsack | 8 | 120 |
| Zero capacity | 0 | 0 |
| All items fit | 10 | 60 |

## Complexity Analysis

- **Exhaustive Search:** \(O(N2^N)\) time, because each of the \(2^N\) subsets may require examining up to \(N\) items.
- **Branch and Bound:** \(O(2^N)\) worst-case time for the current implementation, since its upper-bound calculation takes \(O(N)\) per node, giving a conservative bound of \(O(N2^N)\) in the worst case. Pruning may substantially reduce the number of visited nodes in practice.
- **Auxiliary Space:** \(O(N)\) for the selection arrays and recursion stack used by Branch and Bound.

Both methods guarantee an optimal result for the supported input constraints. Branch and Bound's practical efficiency depends on the strength of its upper bound and how many branches it can prune.

## Concepts Used
- Exhaustive search
- Branch and Bound
- 0/1 Knapsack
- Bitmask enumeration
- Recursion and backtracking
- Upper-bound estimation
- Search-space pruning
- Runtime measurement

## Conclusion
The experiment compares a complete search of all subsets with a recursive search that can eliminate unpromising branches. Both approaches produce the same optimal value, while search-node counts and execution times help illustrate their practical differences.

The current Branch and Bound implementation uses a simple upper bound based on remaining item values. Although valid, this bound is relatively weak, so Branch and Bound is not guaranteed to run faster than Exhaustive Search for every input.
