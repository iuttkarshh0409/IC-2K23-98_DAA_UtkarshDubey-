# Experiment 05: Heap Sort

## 1. Aim

To implement Heap Sort in C++, sort an array of integers in ascending order using a max heap, and analyze the algorithm's time and auxiliary space complexity.

## 2. Problem Statement

Given an array of integers in arbitrary order, sort the elements in ascending order using Heap Sort.

The algorithm constructs a max heap, repeatedly moves the largest element to its correct final position, and restores the heap property for the remaining unsorted elements.

The implementation must handle duplicate values, negative numbers, single-element arrays, and empty arrays.

## 3. Objectives

- Understand the binary heap data structure.
- Implement a max heap using an array.
- Implement the `heapify()` operation.
- Construct a max heap from an unsorted array.
- Implement Heap Sort in C++.
- Analyze best-case, average-case, and worst-case time complexity.
- Understand the auxiliary-space cost of recursive heap operations.

## 4. Theory: Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a binary heap to organize elements.

A **max heap** is a complete binary tree in which every parent is greater than or equal to its children. Consequently, the largest element is always stored at the root.

For an array-based heap with zero-based indexing:

- Parent of index `i`: `(i - 1) / 2`
- Left child of index `i`: `2 * i + 1`
- Right child of index `i`: `2 * i + 2`

Heap Sort operates in two major phases:

1. **Build the max heap:** Rearrange the array so that it satisfies the max-heap property.
2. **Extract the maximum repeatedly:** Swap the root with the last element in the active heap, reduce the heap size, and restore the max-heap property.

Each extracted maximum is placed at the end of the array. Repeating this operation produces ascending order.

Although the lab manual groups Heap Sort under Unit 2, Heap Sort is generally classified as a heap-based sorting algorithm rather than a classic Divide and Conquer algorithm.

## 5. Algorithm

### A. Heapify

1. Assume the current root is the largest element.
2. Calculate the indices of the left and right children.
3. Compare the root with its children.
4. Identify the largest among the root and its valid children.
5. If a child is larger, swap it with the root.
6. Recursively heapify the affected subtree.

### B. Heap Sort

1. Read the array.
2. Build a max heap by calling `heapify()` on internal nodes, starting from the last internal node and moving toward the root.
3. Swap the root with the final element in the active heap.
4. Reduce the active heap size by one.
5. Call `heapify()` on the root to restore the max-heap property.
6. Repeat until only one element remains in the active heap.
7. Display the sorted array.

## 6. Pseudocode

### Heapify

```text
HEAPIFY(A, heapSize, root)

    largest = root
    left = 2 * root + 1
    right = 2 * root + 2

    IF left < heapSize AND A[left] > A[largest]
        largest = left

    IF right < heapSize AND A[right] > A[largest]
        largest = right

    IF largest != root
        SWAP A[root], A[largest]
        HEAPIFY(A, heapSize, largest)
```

### Heap Sort

```text
HEAP-SORT(A)

    n = length(A)

    FOR i = floor(n / 2) - 1 DOWN TO 0
        HEAPIFY(A, n, i)

    FOR i = n - 1 DOWN TO 1
        SWAP A[0], A[i]
        HEAPIFY(A, i, 0)
```

## 7. Flowchart

```text
             ┌──────────────────┐
             │      START       │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Read array A     │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Build max heap   │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Set i = n - 1    │
             └────────┬─────────┘
                      │
             ┌────────▼─────────┐
             │ Is i > 0?        │
             └────┬─────────┬───┘
                  │ Yes     │ No
                  ▼         ▼
          ┌──────────────┐ ┌──────────────┐
          │ Swap root    │ │ Display      │
          │ with A[i]    │ │ sorted array │
          └──────┬───────┘ └──────┬───────┘
                 │                │
          ┌──────▼───────┐ ┌──────▼───────┐
          │ Reduce active│ │     END      │
          │ heap size    │ └──────────────┘
          └──────┬───────┘
                 │
          ┌──────▼───────┐
          │ Heapify root │
          └──────┬───────┘
                 │
          ┌──────▼───────┐
          │ Decrement i  │
          └──────┬───────┘
                 │
                 └───────────────► Check i > 0
```

## 8. Sample Input and Output

### Example 1: Unsorted array

**Input**

```text
Enter the number of elements: 6
Enter 6 integers:
12 11 13 5 6 7
```

**Output**

```text
Sorted array: 5 6 7 11 12 13
```

### Example 2: Duplicate values

**Input**

```text
Enter the number of elements: 6
Enter 6 integers:
4 2 4 1 2 4
```

**Output**

```text
Sorted array: 1 2 2 4 4 4
```

### Example 3: Negative values

**Input**

```text
Enter the number of elements: 5
Enter 5 integers:
-3 7 -10 0 2
```

**Output**

```text
Sorted array: -10 -3 0 2 7
```

### Example 4: Empty array

**Input**

```text
Enter the number of elements: 0
```

**Output**

```text
Sorted array:
```

## 9. Complexity Analysis

Let `n` be the number of elements in the array.

| Case | Time complexity | Explanation |
|---|---|---|
| Best | Θ(n log n) | Heap construction is linear, followed by repeated extractions and heap restoration. |
| Average | Θ(n log n) | Each extraction can require logarithmic heap adjustment. |
| Worst | Θ(n log n) | Heap height is logarithmic, and there are linearly many extraction steps. |
| Heap construction | Θ(n) | Bottom-up heap construction processes internal nodes efficiently. |
| Auxiliary stack | O(log n) | The recursive `heapify()` call stack is bounded by heap height. |

### Time Complexity Derivation

Building the max heap takes:

```text
T_build(n) = Θ(n)
```

The extraction phase performs approximately `n - 1` heap restorations, each taking at most logarithmic time:

```text
T_extract(n) = Θ(n log n)
```

Therefore:

```text
T(n) = Θ(n) + Θ(n log n)
T(n) = Θ(n log n)
```

The overall best-, average-, and worst-case time complexities are Θ(n log n).

## 10. Space Complexity

The implementation sorts the array in place and does not allocate a separate array proportional to the input size.

However, `heapify()` is implemented recursively.

- **Input array:** O(n), excluded from auxiliary space.
- **Additional array storage:** O(1).
- **Recursive call stack:** O(log n) in the worst case.
- **Total auxiliary space for this implementation:** O(log n).

An iterative implementation of `heapify()` can reduce the auxiliary stack usage to O(1).

## 11. Stability

Heap Sort is **not stable** in this implementation. Swapping the root with the last element can change the relative order of elements with equal values.

## 12. Validation and Test Cases

| Test | Input condition | Expected result |
|---|---|---|
| 1 | Unsorted integers | Sorted ascending order |
| 2 | Duplicate values | All values retained and sorted |
| 3 | Negative and positive values | Correct ascending order |
| 4 | Already sorted array | Same ascending order |
| 5 | Reverse-sorted array | Correct ascending order |
| 6 | Single-element array | Same single element |
| 7 | Empty array | Empty sorted output |
| 8 | Negative array size | Error message |
| 9 | Invalid element input | Error message |

## 13. Source File

```text
src/main.cpp
```

The source file contains:

- `heapify()`: restores the max-heap property.
- `heapSort()`: builds the heap and extracts elements into sorted order.
- `main()`: validates input, invokes Heap Sort, and displays the result.

## 14. Learning Outcomes

After completing this experiment, the student should be able to:

- Explain the max-heap property.
- Represent a binary heap using an array.
- Calculate parent and child indices.
- Implement heap construction and heap restoration.
- Implement Heap Sort in C++.
- Derive the Θ(n log n) time complexity.
- Analyze the auxiliary space required by recursive heap operations.
- Explain why Heap Sort is not stable.

## 15. Conclusion

Heap Sort uses a max heap to repeatedly extract the largest remaining element and place it in its final position.

It provides Θ(n log n) best-, average-, and worst-case time complexity. The algorithm sorts in place, although the recursive `heapify()` implementation uses O(log n) auxiliary stack space.

This experiment demonstrates how a heap-based data structure can support efficient sorting.

**Status:** Implementation and initial tests completed.
