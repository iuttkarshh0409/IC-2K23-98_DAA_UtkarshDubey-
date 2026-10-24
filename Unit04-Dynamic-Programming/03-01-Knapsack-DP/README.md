# Experiment 03: 0/1 Knapsack Using Dynamic Programming

## Aim
To implement the 0/1 Knapsack problem using Dynamic Programming in C++ to maximize the total value of selected items without exceeding the knapsack capacity.

## Objectives
- Understand the 0/1 Knapsack optimization problem.
- Implement a Dynamic Programming solution using a two-dimensional array.
- Construct a DP table to evaluate subproblems.
- Determine the optimal selection of items.
- Analyze the time and space complexity of the algorithm.

## Problem Statement
Given `n` items, each having a value and a weight, and a knapsack with capacity `W`, select items to maximize the total value without exceeding the capacity.

Each item can either be selected completely or not selected at all. An item cannot be divided into fractions.

## Theory
Dynamic Programming solves a problem by breaking it into smaller subproblems and storing their results to avoid repeated calculations.

Let `dp[i][w]` represent the maximum value obtainable using the first `i` items with a knapsack capacity of `w`.

For each item, there are two possibilities:

1. Exclude the item and retain the best value obtained from the previous items.
2. Include the item, if its weight does not exceed the current capacity.

The recurrence relation is:

\[
dp[i][w]=
\begin{cases}
0 & i=0 \text{ or } w=0\\
dp[i-1][w] & wt_i>w\\
\max(dp[i-1][w],v_i+dp[i-1][w-wt_i]) & wt_i\leq w
\end{cases}
\]

Here:
- `v_i` is the value of item `i`.
- `wt_i` is the weight of item `i`.
- `W` is the knapsack capacity.

## Algorithm
1. Read the number of items and the knapsack capacity.
2. Read the value and weight of each item.
3. Initialize the DP table with zeros.
4. For every item and every capacity from 0 to `W`:
   - Initially assign the value obtained by excluding the current item.
   - If the item fits, calculate the value obtained by including it.
   - Store the maximum of these two values.
5. Display `dp[n][W]` as the maximum obtainable value.
6. Trace backward through the DP table to identify the selected items.
7. Display the selected items, total weight, and unused capacity.

## Pseudocode
```text id="r1ut8q"
BEGIN
    INPUT n, W
    INPUT values and weights of all items

    INITIALIZE dp[0...n][0...W] TO 0

    FOR i = 1 TO n
        FOR w = 0 TO W
            dp[i][w] = dp[i-1][w]

            IF weight[i] <= w
                includedValue =
                    value[i] + dp[i-1][w-weight[i]]

                dp[i][w] =
                    MAX(dp[i][w], includedValue)
            END IF
        END FOR
    END FOR

    DISPLAY dp[n][W]

    TRACE BACK THROUGH THE DP TABLE
    IDENTIFY selected items

    DISPLAY selected items and total weight
END
```

## Sample Input
```text id="0n2ftr"
3
50
60 10
100 20
120 30
```

The first input specifies three items. The second specifies a knapsack capacity of 50. Each remaining row contains an item's value followed by its weight.

## Sample Output
```text id="o6i7dd"
Maximum obtainable value: 220

Selected items:
Item    Value   Weight
2       100     20
3       120     30

Total selected weight: 50
Unused capacity: 0
```

The optimal selection consists of items 2 and 3, giving a total value of `220` and a total weight of `50`.

## Complexity Analysis

Let `n` be the number of items and `W` be the knapsack capacity.

| Operation | Complexity |
|---|---|
| Filling the DP table | O(nW) |
| Recovering selected items | O(n) |
| Overall time complexity | **O(nW)** |
| Space complexity | **O(nW)** |

The DP table contains `(n + 1) × (W + 1)` entries.

## Test Cases
- The sample input produces a maximum value of `220`.
- A capacity of zero produces a maximum value of zero.
- An item heavier than the available capacity is excluded.
- An item that fits the capacity is selected when beneficial.
- Invalid item counts and capacities are rejected.
- Zero or negative weights are rejected.
- Negative item values are rejected.

## Comparison with Fractional Knapsack

| Property | Fractional Knapsack | 0/1 Knapsack |
|---|---|---|
| Item selection | Fractions allowed | Whole items only |
| Typical approach | Greedy Method | Dynamic Programming |
| Time complexity | O(n log n) | O(nW) |
| Optimal selection | By value-to-weight ratio | By evaluating include/exclude choices |

## Learning Outcomes
- Understood the 0/1 Knapsack problem.
- Implemented Dynamic Programming using a two-dimensional array.
- Applied a recurrence relation to optimize item selection.
- Reconstructed selected items from a DP table.
- Analyzed the time and space complexity of the solution.
- Distinguished 0/1 Knapsack from Fractional Knapsack.

## Conclusion
The 0/1 Knapsack problem was successfully implemented in C++ using Dynamic Programming. The algorithm constructs a DP table to determine the maximum obtainable value and identifies the selected items without exceeding the given capacity.
