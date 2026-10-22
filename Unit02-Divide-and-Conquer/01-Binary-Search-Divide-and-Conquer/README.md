# Experiment 01: Binary Search Using Divide and Conquer

## 1. Aim

To implement Binary Search using the Divide and Conquer technique in C++, and analyze its time and auxiliary space complexity.

## 2. Problem Statement

Given an array of integers sorted in ascending order and a target value, determine whether the target exists in the array using Binary Search.

If the target is present, return its zero-based index. Otherwise, report that the target is not present.

The program must validate the input and ensure that the array is sorted before performing the search.

## 3. Objectives

- Understand the Divide and Conquer algorithmic technique.
- Implement Binary Search recursively in C++.
- Identify the divide, conquer, and base-case steps.
- Validate sorted input before searching.
- Test successful searches, unsuccessful searches, and edge cases.
- Analyze best-case, average-case, and worst-case time complexity.

## 4. Theory: Divide and Conquer

Divide and Conquer is an algorithm design technique that solves a problem by reducing it to smaller subproblems.

It generally consists of three stages:

1. **Divide:** Break the original problem into smaller subproblems.
2. **Conquer:** Solve the relevant subproblem recursively.
3. **Combine:** Combine the results if necessary to obtain the final answer.

In Binary Search, the array is divided around its middle element. The target is compared with the middle element, and only the half that could contain the target is searched.

Because the search interval is reduced by approximately half in every recursive call, Binary Search is significantly more efficient than Linear Search for large, sorted arrays.

## 5. Algorithm

1. Read the number of elements.
2. Validate that the number of elements is positive.
3. Read the array elements.
4. Verify that the array is sorted in ascending order.
5. Read the target value.
6. Call the recursive Binary Search function with the initial range from index `0` to `n - 1`.
7. Calculate the middle index of the current search interval.
8. If the interval is empty, return `-1`.
9. If the middle element equals the target, return the middle index.
10. If the target is smaller than the middle element, recursively search the left half.
11. Otherwise, recursively search the right half.
12. Display the result.

## 6. Pseudocode

```text
BINARY-SEARCH(A, low, high, target)

    IF low > high
        RETURN -1

    mid = low + (high - low) / 2

    IF A[mid] == target
        RETURN mid

    ELSE IF target < A[mid]
        RETURN BINARY-SEARCH(
            A, low, mid - 1, target
        )

    ELSE
        RETURN BINARY-SEARCH(
            A, mid + 1, high, target
        )


MAIN

    READ n

    IF n <= 0
        DISPLAY error
        STOP

    READ array A

    IF A is not sorted in ascending order
        DISPLAY error
        STOP

    READ target

    result = BINARY-SEARCH(A, 0, n - 1, target)

    IF result != -1
        DISPLAY result and result + 1
    ELSE
        DISPLAY "Element not found"
```

## 7. Flowchart

```text
             ┌───────────────┐
             │     START     │
             └───────┬───────┘
                     │
             ┌───────▼───────┐
             │ Read n and    │
             │ array elements│
             └───────┬───────┘
                     │
             ┌───────▼───────┐
             │ Is array      │
             │ sorted?       │
             └───┬───────┬───┘
                 │ Yes   │ No
                 │       ▼
                 │   ┌───────────┐
                 │   │ Show error│
                 │   └─────┬─────┘
                 │         │
                 │      ┌──▼───┐
                 │      │ END  │
                 │      └──────┘
                 │
             ┌───▼───────────┐
             │ Read target   │
             │ and set range │
             └───────┬───────┘
                     │
             ┌───────▼───────┐
             │ Is low > high?│
             └───┬───────┬───┘
                 │ Yes   │ No
                 ▼       ▼
          ┌──────────┐ ┌──────────────┐
          │ Return -1│ │ Calculate mid│
          └────┬─────┘ └──────┬───────┘
               │              │
               │       ┌──────▼───────┐
               │       │ A[mid] ==    │
               │       │ target?      │
               │       └──┬────────┬──┘
               │       Yes│        │No
               │          ▼        ▼
               │    ┌────────┐ ┌─────────────┐
               │    │ Return │ │ Compare with│
               │    │ mid    │ │ target      │
               │    └───┬────┘ └──────┬──────┘
               │        │       ┌─────┴─────┐
               │        │       │           │
               │        │   Target <    Target >
               │        │   A[mid]      A[mid]
               │        │       │           │
               │        │       ▼           ▼
               │        │  Search left  Search right
               │        │   recursively  recursively
               │        │       └─────┬─────┘
               │        │             │
               └────────┴──────┬──────┘
                               ▼
                       ┌──────────────┐
                       │ Display result│
                       └──────┬───────┘
                              │
                       ┌──────▼───────┐
                       │     END      │
                       └──────────────┘
```

## 8. Sample Input and Output

### Example 1: Successful Search

**Input**

```text
Enter the number of elements: 7
Enter 7 elements in sorted order:
2 5 8 12 16 23 38
Enter the element to search: 16
```

**Output**

```text
Element found at index: 4
Position (1-based): 5
```

### Example 2: Unsuccessful Search

**Input**

```text
Enter the number of elements: 7
Enter 7 elements in sorted order:
2 5 8 12 16 23 38
Enter the element to search: 10
```

**Output**

```text
Element not found in the array.
```

### Example 3: Invalid Array

**Input**

```text
Enter the number of elements: 4
Enter 4 elements in sorted order:
10 5 20 30
```

**Output**

```text
Error: array must be sorted in ascending order.
```

## 9. Complexity Analysis

Let `n` be the number of elements in the array.

| Case | Time Complexity | Explanation |
|---|---|---|
| Best case | Θ(1) | The target is found at the middle element in the first comparison. |
| Average case | Θ(log n) | The search interval is repeatedly halved. |
| Worst case | Θ(log n) | The algorithm continues until the target is found or the interval becomes empty. |
| Auxiliary space | Θ(log n) | Recursive calls consume stack space proportional to the recursion depth. |

The time complexity follows the recurrence:

```text
T(n) = T(n / 2) + Θ(1)
```

Solving this recurrence gives:

```text
T(n) = Θ(log n)
```

The auxiliary space complexity is logarithmic because the maximum recursion depth is proportional to `log₂(n)`.

## 10. Validation and Test Cases

| Test | Input condition | Expected result |
|---|---|---|
| 1 | Target exists in the middle | Correct index |
| 2 | Target is absent | Element not found |
| 3 | Array contains one element | Correct result |
| 4 | Target is the first element | Correct index |
| 5 | Target is the last element | Correct index |
| 6 | Array is not sorted | Error message |
| 7 | Number of elements is zero or negative | Error message |
| 8 | Invalid numeric input | Error message |

**Validation status:** The implementation compiled and the initial test cases passed.

## 11. Source File

```text
src/main.cpp
```

The source file contains the recursive Binary Search implementation, input validation, sorted-order verification, and result display logic.

## 12. Learning Outcomes

After completing this experiment, the student should be able to:

- Explain the Divide and Conquer technique.
- Implement recursive Binary Search using C++.
- Identify recursive base cases and recursive calls.
- Explain why sorted input is required.
- Derive logarithmic time complexity using a recurrence relation.
- Explain the auxiliary-space cost of recursion.
- Validate an algorithm using normal, boundary, and invalid inputs.

## 13. Conclusion

Binary Search using Divide and Conquer efficiently searches a sorted array by repeatedly eliminating half of the remaining search interval. Its best-case time complexity is Θ(1), while its average- and worst-case time complexities are Θ(log n).

The experiment demonstrates the practical use of recursion, base cases, input validation, and asymptotic complexity analysis in algorithm design.

**Status:** Experiment 01 implementation and initial tests completed.
