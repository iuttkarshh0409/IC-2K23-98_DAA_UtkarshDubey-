# Experiment 04: Quick Sort Using Divide and Conquer

## 1. Aim

To implement Quick Sort using the Divide and Conquer technique in C++, verify the correctness of the sorted output, and analyze its best-case, average-case, and worst-case time complexity.

## 2. Problem Statement

Given an array of integers in arbitrary order, sort the elements in ascending order using Quick Sort.

The algorithm selects a pivot, partitions the array around it, and recursively sorts the resulting subarrays.

The implementation must handle duplicate values, negative numbers, single-element arrays, and empty arrays.

## 3. Objectives

- Understand the Divide and Conquer technique.
- Implement Quick Sort recursively in C++.
- Understand pivot selection and array partitioning.
- Implement the Lomuto partition scheme.
- Analyze best-case, average-case, and worst-case time complexity.
- Understand the impact of pivot selection on performance.
- Verify sorting correctness using different input cases.

## 4. Theory: Divide and Conquer

Quick Sort is a comparison-based sorting algorithm that uses Divide and Conquer.

It consists of three main stages:

1. **Divide:** Partition the array around a pivot so that elements less than or equal to the pivot appear on its left and greater elements appear on its right.
2. **Conquer:** Recursively sort the left and right partitions.
3. **Combine:** No separate merge operation is required because partitioning places the pivot in its final sorted position, and the recursive calls sort the remaining partitions.

This experiment uses the **Lomuto partition scheme**, which selects the last element of the current subarray as the pivot.

## 5. Algorithm

### A. Quick Sort

1. If the subarray contains zero or one element, return.
2. Partition the subarray and obtain the pivot's final index.
3. Recursively sort the elements to the left of the pivot.
4. Recursively sort the elements to the right of the pivot.

### B. Partition Operation

1. Select the last element as the pivot.
2. Initialize a boundary index immediately before the current subarray.
3. Traverse all elements before the pivot.
4. When an element is less than or equal to the pivot, advance the boundary and swap the element into the left partition.
5. Swap the pivot into the position immediately after the boundary.
6. Return the pivot's final index.

## 6. Pseudocode

### Quick Sort

```text id="e8s3b1"
QUICK-SORT(A, low, high)

    IF low >= high
        RETURN

    pivotIndex = PARTITION(A, low, high)

    QUICK-SORT(A, low, pivotIndex - 1)

    QUICK-SORT(A, pivotIndex + 1, high)
```

### Lomuto Partition

```text id="n4k7p2"
PARTITION(A, low, high)

    pivot = A[high]
    i = low - 1

    FOR j = low TO high - 1
        IF A[j] <= pivot
            i = i + 1
            SWAP A[i], A[j]

    SWAP A[i + 1], A[high]

    RETURN i + 1
```

## 7. Flowchart

```text id="m7c2q5"
             ┌──────────────────┐
             │      START       │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Read array A     │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Call QUICK-SORT  │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Is low >= high?  │
             └────┬────────┬────┘
                  │ Yes    │ No
                  ▼        ▼
             ┌────────┐ ┌──────────────┐
             │ Return │ │ Partition    │
             └───┬────┘ │ around pivot │
                 │      └──────┬───────┘
                 │             │
                 │      ┌──────▼────────┐
                 │      │ Get pivot     │
                 │      │ final index   │
                 │      └──────┬────────┘
                 │             │
                 │      ┌──────▼────────┐
                 │      │ Sort left     │
                 │      │ partition     │
                 │      └──────┬────────┘
                 │             │
                 │      ┌──────▼────────┐
                 │      │ Sort right    │
                 │      │ partition     │
                 │      └──────┬────────┘
                 └─────────────┤
                               │
                      ┌────────▼─────────┐
                      │ Display sorted   │
                      │ array            │
                      └────────┬─────────┘
                               │
                      ┌────────▼─────────┐
                      │       END        │
                      └──────────────────┘
```

## 8. Sample Input and Output

### Example 1: Mixed values

**Input**

```text id="q2w6j8"
Enter the number of elements: 7
Enter 7 integers:
10 7 8 9 1 5 3
```

**Output**

```text id="k5v8z3"
Sorted array: 1 3 5 7 8 9 10
```

### Example 2: Duplicate values

**Input**

```text id="c6p1r4"
Enter the number of elements: 6
Enter 6 integers:
4 2 4 1 2 4
```

**Output**

```text id="b9m3t7"
Sorted array: 1 2 2 4 4 4
```

### Example 3: Negative values

**Input**

```text id="r3x5n8"
Enter the number of elements: 5
Enter 5 integers:
-3 7 -10 0 2
```

**Output**

```text id="v7d2f9"
Sorted array: -10 -3 0 2 7
```

### Example 4: Empty array

**Input**

```text id="t4y8k2"
Enter the number of elements: 0
```

**Output**

```text id="j6p3w5"
Sorted array:
```

## 9. Complexity Analysis

Let `n` be the number of elements in the array.

| Case | Time complexity | Explanation |
|---|---|---|
| Best | Θ(n log n) | The pivot divides the array into approximately equal partitions. |
| Average | Θ(n log n) | Partitions are reasonably balanced on average. |
| Worst | Θ(n²) | Each partition leaves one empty side and one subarray of size `n - 1`. |
| Auxiliary stack, average | Θ(log n) | Recursion depth is logarithmic for balanced partitions. |
| Auxiliary stack, worst | Θ(n) | Recursion depth becomes linear for highly unbalanced partitions. |

### Best and Average Case

When the partitions are approximately balanced, the recurrence is:

```text id="u3f5a7"
T(n) = 2T(n / 2) + Θ(n)
```

Therefore:

```text id="x9c4m2"
T(n) = Θ(n log n)
```

### Worst Case

When the pivot repeatedly creates partitions of sizes `0` and `n - 1`, the recurrence is:

```text id="d8g2h6"
T(n) = T(n - 1) + Θ(n)
```

Therefore:

```text id="a5k7p1"
T(n) = Θ(n²)
```

## 10. Pivot Selection and Performance

This implementation always chooses the last element as the pivot.

Consequently, already sorted arrays, reverse-sorted arrays, and arrays with many equal values can produce highly unbalanced partitions with this particular partition scheme.

The Lomuto implementation uses the condition `A[j] <= pivot`, so an array containing equal values can repeatedly place most elements on the same side of the pivot.

Alternative strategies include randomized pivot selection, median-of-three pivot selection, and three-way partitioning. These can improve practical behavior on certain inputs, although the worst-case complexity of ordinary Quick Sort remains quadratic.

## 11. Stability and Space Usage

### Stability

This implementation is **not guaranteed to be stable**. Swapping elements during partitioning can change the relative order of equal elements.

### Space Complexity

Quick Sort partitions the array in place, so it does not require a separate array proportional to `n` for the sorting operation. However, recursive calls consume stack space.

- Average auxiliary stack space: Θ(log n).
- Worst-case auxiliary stack space: Θ(n).

## 12. Validation and Test Cases

| Test | Input condition | Expected result |
|---|---|---|
| 1 | Mixed integers | Sorted ascending order |
| 2 | Duplicate values | All values retained and sorted |
| 3 | Negative and positive values | Correct ascending order |
| 4 | Already sorted array | Original ascending order |
| 5 | Reverse-sorted array | Correct ascending order |
| 6 | Single-element array | Same single element |
| 7 | Empty array | Empty sorted output |
| 8 | Negative array size | Error message |
| 9 | Invalid element input | Error message |

## 13. Source File

```text id="p6r8z2"
src/main.cpp
```

The source file contains the `partitionArray()` helper function, the recursive `quickSort()` implementation, input validation, and sorted-array output.

## 14. Learning Outcomes

After completing this experiment, the student should be able to:

- Explain the Divide and Conquer technique.
- Implement Quick Sort using C++.
- Explain the Lomuto partition scheme.
- Understand how pivot choice affects partition balance.
- Derive best-, average-, and worst-case time complexity.
- Analyze recursive stack usage.
- Explain why Quick Sort is not guaranteed to be stable.
- Validate sorting algorithms using diverse input cases.

## 15. Conclusion

Quick Sort sorts an array by partitioning it around a pivot and recursively sorting the resulting subarrays.

It achieves Θ(n log n) average-case time complexity but can degrade to Θ(n²) in the worst case when partitions are repeatedly unbalanced. This experiment demonstrates the importance of partitioning strategy and pivot selection in practical algorithm performance.

**Status:** Implementation and initial tests completed.
