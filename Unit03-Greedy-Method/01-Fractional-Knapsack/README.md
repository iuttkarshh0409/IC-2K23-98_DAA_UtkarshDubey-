# Experiment 01: Fractional Knapsack

## Aim
To implement the Fractional Knapsack problem using the Greedy Method and maximize the total value of items placed in a knapsack with limited capacity.

## Objectives
- Understand the Greedy Method and its decision-making strategy.
- Calculate the value-to-weight ratio of each item.
- Select items in descending order of value-to-weight ratio.
- Allow fractions of items to be selected when the remaining capacity is insufficient for a complete item.
- Analyze the algorithm's time and space complexity.

## Problem Statement
Given `n` items, each having a value and a weight, and a knapsack with a fixed capacity, determine the maximum total value that can be obtained. Items can be divided into fractions.

## Theory
The Fractional Knapsack problem uses a greedy strategy. At each step, the algorithm selects the item with the highest value-to-weight ratio.

The ratio is calculated as:

\[
\text{Ratio}=\frac{\text{Value}}{\text{Weight}}
\]

Items are sorted in descending order of this ratio. If an item fits entirely, it is selected. Otherwise, the algorithm selects the fraction that fits in the remaining capacity.

Unlike the 0/1 Knapsack problem, Fractional Knapsack permits partial selection of an item.

## Algorithm
1. Read the number of items and the knapsack capacity.
2. Read each item's value and weight.
3. Calculate the value-to-weight ratio for every item.
4. Sort the items in descending order of their ratios.
5. Initialize the remaining capacity and total value to the given capacity and zero, respectively.
6. Traverse the sorted items:
   - If the complete item fits, select it and update the remaining capacity and total value.
   - Otherwise, select the fraction that fits, update the total value, and stop.
7. Display the selected items, fractions, maximum total value, and unused capacity.

## Pseudocode
```text
BEGIN
    INPUT n, capacity

    FOR each item i from 1 to n
        INPUT value[i], weight[i]
        ratio[i] = value[i] / weight[i]
    END FOR

    SORT items by ratio in descending order

    remainingCapacity = capacity
    totalValue = 0

    FOR each item in sorted order
        IF remainingCapacity <= 0
            BREAK
        END IF

        IF item.weight <= remainingCapacity
            totalValue = totalValue + item.value
            remainingCapacity = remainingCapacity - item.weight
        ELSE
            fraction = remainingCapacity / item.weight
            totalValue = totalValue + fraction * item.value
            remainingCapacity = 0
        END IF
    END FOR

    OUTPUT totalValue, remainingCapacity
END
```

## Sample Input
```text
3
50
60 10
100 20
120 30
```

## Sample Output
```text
Maximum obtainable value: 240.00
Unused capacity: 0.00
```

## Complexity Analysis

| Operation | Complexity |
|---|---|
| Reading and processing items | O(n) |
| Sorting items | O(n log n) |
| Selecting items | O(n) |
| **Overall time complexity** | **O(n log n)** |
| Auxiliary storage for items | **O(n)** |

## Test Cases
- Standard input produces a maximum value of `240.00`.
- Capacity smaller than every item’s weight allows a fraction of the best item to be selected.
- Capacity greater than the total weight allows all items to be selected.
- Zero or negative capacity is rejected.
- Zero or negative item weight is rejected.
- Item counts outside the supported range of 1 to 100 are rejected.

## Learning Outcomes
- Understood the greedy-choice strategy.
- Implemented sorting using a custom comparison function.
- Applied value-to-weight ratios to prioritize items.
- Learned how fractional selection affects the optimal solution.
- Analyzed the time and space complexity of a greedy algorithm.

## Conclusion
The Fractional Knapsack problem was successfully implemented in C++ using the Greedy Method. The algorithm sorts items by value-to-weight ratio and selects complete items or fractions to maximize the total value within the available capacity.
