# Experiment 02: Maximum and Minimum Using Divide and Conquer

## 1. Aim

To find the maximum and minimum elements of an array using the Divide and Conquer technique in C++, and analyze the algorithm's time and auxiliary space complexity.

## 2. Problem Statement

Given an array of `n` integers, determine the minimum and maximum elements using a recursive Divide and Conquer algorithm.

The program divides the array into smaller subarrays, determines the minimum and maximum of each subarray, and combines the results to obtain the overall minimum and maximum.

The implementation must handle single-element arrays, duplicate values, negative numbers, and invalid input sizes.

## 3. Objectives

- Understand the Divide and Conquer algorithmic technique.
- Implement recursive minimum and maximum calculation in C++.
- Identify the base cases for one-element and two-element subarrays.
- Combine results from recursively processed subarrays.
- Analyze the time complexity using a recurrence relation.
- Understand the comparison-efficiency advantage of paired min-max algorithms.

## 4. Theory: Divide and Conquer

Divide and Conquer solves a problem by dividing it into smaller subproblems, solving those subproblems recursively, and combining their results.

This experiment uses three stages:

1. **Divide:** Split the array into two halves.
2. **Conquer:** Recursively calculate the minimum and maximum of each half.
3. **Combine:** Compare the two minimum values and the two maximum values to determine the final answer.

The recursion terminates when the subarray contains one or two elements.

For a single element, the same value is both the minimum and maximum. For two elements, one comparison determines which value is smaller and which is larger.

## 5. Algorithm

1. Read the number of elements `n`.
2. Validate that `n` is positive.
3. Read the array elements.
4. Call `findMinMax(arr, 0, n - 1)`.
5. If the current subarray contains one element, return that element as both minimum and maximum.
6. If it contains two elements, compare them and return the smaller and larger values.
7. Otherwise, calculate the middle index.
8. Recursively find the minimum and maximum in the left half.
9. Recursively find the minimum and maximum in the right half.
10. Combine the results by selecting the smaller minimum and larger maximum.
11. Display the final minimum and maximum.

## 6. Pseudocode

```text
FIND-MIN-MAX(A, low, high)

    IF low == high
        RETURN (A[low], A[low])

    IF high == low + 1
        IF A[low] < A[high]
            RETURN (A[low], A[high])
        ELSE
            RETURN (A[high], A[low])

    mid = low + (high - low) / 2

    (leftMin, leftMax) =
        FIND-MIN-MAX(A, low, mid)

    (rightMin, rightMax) =
        FIND-MIN-MAX(A, mid + 1, high)

    minimum = MIN(leftMin, rightMin)
    maximum = MAX(leftMax, rightMax)

    RETURN (minimum, maximum)


MAIN

    READ n

    IF n <= 0
        DISPLAY error
        STOP

    READ array A

    (minimum, maximum) =
        FIND-MIN-MAX(A, 0, n - 1)

    DISPLAY minimum
    DISPLAY maximum
```

## 7. Flowchart

```text
              ┌──────────────────┐
              │      START       │
              └────────┬─────────┘
                       │
              ┌────────▼─────────┐
              │ Read n and array │
              └────────┬─────────┘
                       │
              ┌────────▼─────────┐
              │ Is n positive?   │
              └────┬────────┬────┘
                   │ Yes    │ No
                   │        ▼
                   │   ┌────────────┐
                   │   │ Show error │
                   │   └─────┬──────┘
                   │         │
                   │         ▼
                   │        END
                   ▼
          ┌───────────────────────┐
          │ Call FIND-MIN-MAX     │
          │ with low and high     │
          └───────────┬───────────┘
                      │
             ┌────────▼────────┐
             │ One element?    │
             └────┬────────┬───┘
                  │ Yes    │ No
                  ▼        ▼
           ┌────────────┐  ┌─────────────────┐
           │ Return the │  │ Two elements?   │
           │ same value │  └────┬────────┬───┘
           └──────┬─────┘       │ Yes    │ No
                  │             ▼        ▼
                  │      ┌───────────┐ ┌────────────┐
                  │      │ Compare   │ │ Divide at  │
                  │      │ two values│ │ midpoint   │
                  │      └─────┬─────┘ └─────┬──────┘
                  │            │             │
                  │            │      ┌──────▼───────┐
                  │            │      │ Recursively  │
                  │            │      │ solve halves │
                  │            │      └──────┬───────┘
                  │            │             │
                  │            │      ┌──────▼───────┐
                  │            │      │ Combine min  │
                  │            │      │ and max      │
                  │            │      └──────┬───────┘
                  └────────────┴─────────────┘
                               │
                      ┌────────▼─────────┐
                      │ Display minimum  │
                      │ and maximum      │
                      └────────┬─────────┘
                               │
                      ┌────────▼─────────┐
                      │       END        │
                      └──────────────────┘
```

## 8. Sample Input and Output

### Example 1: Mixed positive and negative values

**Input**

```text
Enter the number of elements: 6
Enter 6 integers:
12 -5 30 7 0 18
```

**Output**

```text
Minimum element: -5
Maximum element: 30
```

### Example 2: Single element

**Input**

```text
Enter the number of elements: 1
Enter 1 integers:
42
```

**Output**

```text
Minimum element: 42
Maximum element: 42
```

### Example 3: Duplicate values

**Input**

```text
Enter the number of elements: 5
Enter 5 integers:
8 8 8 8 8
```

**Output**

```text
Minimum element: 8
Maximum element: 8
```

### Example 4: Invalid input size

**Input**

```text
Enter the number of elements: 0
```

**Output**

```text
Error: number of elements must be positive.
```

## 9. Complexity Analysis

Let `n` be the number of elements in the array.

| Metric | Complexity | Explanation |
|---|---|---|
| Time complexity | Θ(n) | Each element is processed through the recursive subproblems, with constant work per combination. |
| Auxiliary recursion stack | Θ(log n) | The recursion depth grows logarithmically as the array is halved. |
| Additional result storage | O(1) per active call | Each call stores a constant number of indices and min-max results. |

### Recurrence relation

For the general case, the recurrence is:

```text
T(n) = 2T(n / 2) + Θ(1)
```

Applying the Master Theorem:

```text
T(n) = Θ(n)
```

The algorithm has linear time complexity because the two recursive calls process disjoint halves of the array.

## 10. Comparison Analysis

A straightforward method finds the minimum and maximum independently, requiring up to `2n - 2` comparisons.

A paired min-max algorithm can reduce the number of comparisons by processing elements in pairs and comparing each pair before updating the overall minimum and maximum.

For the specific divide-and-conquer implementation in this experiment, the number of comparisons depends on the recursive partitioning and the base cases used.

For a balanced split with `n` a power of two, the recurrence for the number of comparisons is:

```text
C(n) = 2C(n / 2) + 2
C(1) = 0
C(2) = 1
```

For powers of two, this gives:

```text
C(n) = 3n / 2 - 2
```

This comparison count assumes the implementation uses the one-element and two-element base cases shown in the source code.

## 11. Validation and Test Cases

| Test | Input condition | Expected result |
|---|---|---|
| 1 | Positive and negative values | Correct minimum and maximum |
| 2 | Single-element array | Same value for both |
| 3 | All elements equal | Same value for both |
| 4 | Array with negative values | Correct extrema |
| 5 | Minimum at first position | Correct minimum |
| 6 | Maximum at last position | Correct maximum |
| 7 | Zero elements | Error message |
| 8 | Negative array size | Error message |
| 9 | Invalid element input | Error message |

## 12. Source File

```text
src/main.cpp
```

The source file contains the recursive `findMinMax()` function, the `MinMax` result structure, input validation, and output formatting.

## 13. Learning Outcomes

After completing this experiment, the student should be able to:

- Explain the Divide and Conquer technique.
- Implement recursive min-max calculation in C++.
- Identify recursion base cases.
- Combine results from subproblems.
- Derive time complexity using a recurrence relation.
- Analyze auxiliary recursion-stack space.
- Explain how comparison-efficient min-max algorithms reduce redundant comparisons.

## 14. Conclusion

The experiment demonstrates how Divide and Conquer can be used to determine the minimum and maximum values in an array through recursive decomposition.

The algorithm runs in Θ(n) time and uses Θ(log n) auxiliary recursion-stack space. Its paired base cases and combined results also demonstrate how algorithm design can reduce the number of comparisons required to solve a problem.

**Status:** Implementation and initial tests completed.
