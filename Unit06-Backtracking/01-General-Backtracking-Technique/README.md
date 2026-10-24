# Experiment 01: General Backtracking Technique

## Aim
To understand and implement the general backtracking technique in C++ by exploring possible choices, undoing decisions, and finding subsets whose sum equals a given target.

## Problem Statement
Write a C++ program that accepts a set of positive integers and a target sum. Use backtracking to find and display all subsets whose elements add up to the target.

## Theory
**Backtracking** is an algorithmic technique that explores possible solutions by making decisions one at a time. If a choice does not lead to a solution, the algorithm reverses that choice and explores another possibility.

The general backtracking process consists of:

1. **Choose:** Make a possible decision.
2. **Explore:** Recursively investigate the consequences of that decision.
3. **Undo:** Reverse the decision before exploring an alternative.

In this experiment, each number has two possible choices: include it in the current subset or exclude it.

## Algorithm
1. Read the number of elements.
2. Read the positive integers.
3. Read the target sum.
4. Start the recursive backtracking function at index `0` with current sum `0`.
5. If the current sum equals the target, display the selected subset.
6. If all elements have been considered, return.
7. Include the current element and recursively explore the next index.
8. Undo the inclusion by resetting the choice.
9. Exclude the current element and recursively explore the next index.
10. If no matching subset is found, display an appropriate message.

## Pseudocode

```text id="9f3t5a"
BACKTRACK(index, currentSum)
    if currentSum = target
        display selected subset
        mark solution found
        return

    if index = n
        return

    chosen[index] = true
    BACKTRACK(index + 1, currentSum + numbers[index])

    chosen[index] = false

    BACKTRACK(index + 1, currentSum)

MAIN
    Read n and positive integers
    Read target sum
    BACKTRACK(0, 0)

    if no solution found
        display no matching subset
```

## Sample Input

```text id="g7b3k2"
4
3 4 5 2
7
```

## Sample Output

```text id="n2c8w4"
Subsets with sum 7:
Subset: { 3 4 }
Subset: { 5 2 }
```

## Complexity Analysis

Let \(n\) be the number of input elements.

| Metric | Complexity |
|---|---|
| Worst-case time | \(O(2^n)\) |
| Auxiliary recursion space | \(O(n)\) |
| Choice array space | \(O(n)\) |

Each element has two possible decisions, so the algorithm may explore up to \(2^n\) combinations. The total running time also depends on the number of solutions printed.

## Edge Cases
- A target sum of zero, which produces the empty subset.
- No subset can form the target.
- A target equal to one input element.
- Multiple subsets with the same target sum.
- The smallest permitted input size.
- Invalid element counts or non-positive input values.

## Learning Outcomes
- Understood the general backtracking strategy.
- Implemented recursive decision-making in C++.
- Learned how to undo a decision before exploring another branch.
- Applied backtracking to subset-sum exploration.
- Analyzed exponential time complexity and linear auxiliary space.

## Conclusion
The program demonstrates the general backtracking technique by exploring inclusion and exclusion decisions for each input element. It successfully identifies subsets that match the target sum and illustrates how undoing choices enables systematic exploration of alternative solutions.
