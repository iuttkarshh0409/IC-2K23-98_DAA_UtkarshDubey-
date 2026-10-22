# Experiment 03: Merge Sort Using Divide and Conquer

## 1. Aim

To implement the Merge Sort algorithm using the Divide and Conquer technique in C++, verify its sorting correctness, and analyze its time and auxiliary space complexity.

## 2. Problem Statement

Given an array of integers in arbitrary order, sort the elements in ascending order using Merge Sort.

The algorithm must divide the array into smaller subarrays, recursively sort them, and merge the sorted subarrays to produce the final sorted array.

The implementation should handle duplicate values, negative numbers, single-element arrays, and empty arrays.

## 3. Objectives

- Understand the Divide and Conquer technique.
- Implement Merge Sort recursively in C++.
- Understand the role of the merge operation.
- Sort arrays containing positive, negative, and duplicate values.
- Verify the correctness of the sorted output.
- Analyze the algorithm's time and auxiliary space complexity.

## 4. Theory: Divide and Conquer

Divide and Conquer is an algorithm design technique that breaks a problem into smaller subproblems, solves them recursively, and combines their results.

Merge Sort uses three stages:

1. **Divide:** Split the array into two approximately equal halves.
2. **Conquer:** Recursively sort both halves.
3. **Combine:** Merge the two sorted halves into one sorted sequence.

The division continues until each subarray contains at most one element. Such a subarray is already sorted.

The merge operation compares the front elements of the two sorted halves, copies the smaller element into a temporary array, and continues until all elements have been merged. The merged elements are then copied back into the original array.

## 5. Algorithm

### A. Merge Sort

1. If the subarray contains zero or one element, return.
2. Calculate the middle index.
3. Recursively sort the left half.
4. Recursively sort the right half.
5. Merge both sorted halves.

### B. Merge Operation

1. Initialize pointers to the beginning of the left and right halves.
2. Compare the elements currently pointed to by both pointers.
3. Append the smaller element to a temporary array.
4. Advance the pointer associated with the selected element.
5. Copy any remaining elements from either half.
6. Copy the temporary array back into the corresponding portion of the original array.

## 6. Pseudocode

### Merge Sort

```text id="3c7fb3"
MERGE-SORT(A, left, right)

    IF left >= right
        RETURN

    mid = left + (right - left) / 2

    MERGE-SORT(A, left, mid)

    MERGE-SORT(A, mid + 1, right)

    MERGE(A, left, mid, right)
```

### Merge Operation

```text id="b2eq72"
MERGE(A, left, mid, right)

    CREATE empty temporary array temp

    i = left
    j = mid + 1

    WHILE i <= mid AND j <= right
        IF A[i] <= A[j]
            APPEND A[i] TO temp
            i = i + 1
        ELSE
            APPEND A[j] TO temp
            j = j + 1

    WHILE i <= mid
        APPEND A[i] TO temp
        i = i + 1

    WHILE j <= right
        APPEND A[j] TO temp
        j = j + 1

    COPY temp BACK INTO A[left ... right]
```

## 7. Flowchart

```text id="6h7x0n"
            ┌──────────────────┐
            │      START       │
            └────────┬─────────┘
                     │
            ┌────────▼─────────┐
            │ Read array A     │
            └────────┬─────────┘
                     │
            ┌────────▼─────────┐
            │ Call MERGE-SORT  │
            └────────┬─────────┘
                     │
            ┌────────▼─────────┐
            │ Is left >= right?│
            └────┬─────────┬──┘
                 │ Yes     │ No
                 ▼         ▼
          ┌────────────┐ ┌──────────────┐
          │ Return     │ │ Calculate mid│
          └─────┬──────┘ └──────┬───────┘
                │                │
                │        ┌───────▼────────┐
                │        │ Sort left half │
                │        │ recursively     │
                │        └───────┬────────┘
                │                │
                │        ┌───────▼────────┐
                │        │ Sort right half│
                │        │ recursively     │
                │        └───────┬────────┘
                │                │
                │        ┌───────▼────────┐
                │        │ Merge sorted   │
                │        │ halves         │
                │        └───────┬────────┘
                └────────────────┤
                                 │
                        ┌────────▼────────┐
                        │ Display sorted  │
                        │ array           │
                        └────────┬────────┘
                                 │
                        ┌────────▼────────┐
                        │       END       │
                        └─────────────────┘
```

## 8. Sample Input and Output

### Example 1: Unsorted array

**Input**

```text id="z06ycb"
Enter the number of elements: 6
Enter 6 integers:
38 27 43 3 9 82
```

**Output**

```text id="e8x6k4"
Sorted array: 3 9 27 38 43 82
```

### Example 2: Duplicate values

**Input**

```text id="q8c2f1"
Enter the number of elements: 5
Enter 5 integers:
4 2 4 1 2
```

**Output**

```text id="t7z0a3"
Sorted array: 1 2 2 4 4
```

### Example 3: Negative values

**Input**

```text id="g5n8sp"
Enter the number of elements: 5
Enter 5 integers:
-3 7 -10 0 2
```

**Output**

```text id="k1b4x7"
Sorted array: -10 -3 0 2 7
```

### Example 4: Empty array

**Input**

```text id="w5n9za"
Enter the number of elements: 0
```

**Output**

```text id="a4p8cd"
Sorted array:
```

## 9. Complexity Analysis

Let `n` be the number of elements in the array.

| Case | Time Complexity | Explanation |
|---|---|---|
| Best case | Θ(n log n) | The algorithm continues dividing and merging even if the array is already sorted. |
| Average case | Θ(n log n) | Each recursion level processes all elements during merging. |
| Worst case | Θ(n log n) | The splitting structure remains balanced regardless of input order. |
| Auxiliary space | Θ(n) | Temporary arrays store elements during merging. |
| Recursion stack | Θ(log n) | The recursion depth is logarithmic. |

### Recurrence Relation

For simplicity, assuming equal-sized halves:

```text id="m5z1v8"
T(n) = 2T(n / 2) + Θ(n)
```

Using the Master Theorem:

```text id="c3q9w6"
T(n) = Θ(n log n)
```

The two recursive calls sort the two halves, while the merge operation takes linear time relative to the size of the current subarray.

## 10. Stability and Space Usage

### Stability

The implementation uses `A[i] <= A[j]` during merging. When two elements have equal values, the element from the left half is selected first.

This preserves the relative order of equal elements, making the implementation stable.

### Space Usage

The merge operation allocates a temporary vector proportional to the current subarray size. The overall auxiliary storage is Θ(n), while the recursion stack requires Θ(log n) additional space.

## 11. Validation and Test Cases

| Test | Input condition | Expected result |
|---|---|---|
| 1 | Unsorted positive integers | Sorted ascending order |
| 2 | Duplicate elements | All values retained and sorted |
| 3 | Negative and positive values | Correct ascending order |
| 4 | Already sorted array | Original order preserved |
| 5 | Reverse-sorted array | Correct ascending order |
| 6 | Single-element array | Same single element |
| 7 | Empty array | Empty sorted output |
| 8 | Negative array size | Error message |
| 9 | Invalid element input | Error message |

## 12. Source File

```text id="d5p8qa"
src/main.cpp
```

The source file contains the recursive `mergeSort()` function, the `merge()` helper function, input validation, and sorted-array output.

## 13. Learning Outcomes

After completing this experiment, the student should be able to:

- Explain the Divide and Conquer technique.
- Implement Merge Sort recursively in C++.
- Explain how merging combines sorted subarrays.
- Derive the time complexity using a recurrence relation.
- Analyze auxiliary storage and recursion depth.
- Understand the stability of a sorting algorithm.
- Validate sorting correctness using diverse input cases.

## 14. Conclusion

Merge Sort sorts an array by recursively dividing it into smaller subarrays and merging the sorted results.

Its best-, average-, and worst-case time complexities are all Θ(n log n). The algorithm provides predictable performance and stable sorting, at the cost of Θ(n) auxiliary storage.

**Status:** Implementation and initial tests completed.
