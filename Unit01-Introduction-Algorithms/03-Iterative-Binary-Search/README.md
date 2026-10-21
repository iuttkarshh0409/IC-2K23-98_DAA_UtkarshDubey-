# Experiment 03: Iterative Binary Search

**Course:** Design & Analysis of Algorithms Lab  
**Course Code:** IC-709 B  
**Unit:** Unit 1 — Introduction to Algorithms & Performance Analysis  
**Experiment:** Iterative Binary Search  
**Programming Language:** C++17  
**Status:** Implementation and testing in progress

---

## 1. Aim

To implement iterative binary search in C++ to locate a target element in a sorted array and analyze its time and space complexity.

## 2. Objectives

- Understand the divide-and-conquer principle used in binary search.
- Implement binary search using an iterative approach.
- Identify the role of the `low`, `mid`, and `high` indices.
- Validate that the input array is sorted in ascending order.
- Analyze best-case, average-case, and worst-case time complexity.
- Evaluate the implementation using normal, boundary, and invalid-input test cases.

## 3. Problem Statement

Given an array of `n` integers sorted in ascending order and a target value, determine whether the target exists in the array.

If the target is present, return its index. Otherwise, return `-1`.

The implementation must use an iterative binary search algorithm and must not use recursion.

### Example

**Input**

```text
Enter array size: 7
Enter 7 sorted integers: 5 12 18 23 31 42 57
Enter target element: 31
```

**Output**

```text
Element found at index 4.
```

## 4. Algorithm Design

### Approach

Binary search repeatedly divides the current search interval into two halves.

1. Initialize `low` to `0`.
2. Initialize `high` to `n - 1`.
3. While `low <= high`, calculate the middle index.
4. If the middle element equals the target, return its index.
5. If the middle element is smaller than the target, continue searching the right half.
6. If the middle element is greater than the target, continue searching the left half.
7. If the interval becomes empty, return `-1`.

### Pseudocode

```text
ALGORITHM IterativeBinarySearch(A, n, target)

    low ← 0
    high ← n - 1

    WHILE low <= high DO

        mid ← low + floor((high - low) / 2)

        IF A[mid] = target THEN
            RETURN mid

        ELSE IF A[mid] < target THEN
            low ← mid + 1

        ELSE
            high ← mid - 1

        END IF

    END WHILE

    RETURN -1

END ALGORITHM
```

### Important Precondition

The input array must be sorted in ascending order. Binary search relies on this ordering to eliminate half of the remaining search interval after each unsuccessful comparison.

The implementation checks the ordering of the input and rejects unsorted arrays.

## 5. Flowchart

The algorithm follows this control flow:

```text
              START
                |
                v
       Input sorted array
       and target element
                |
                v
       low = 0, high = n - 1
                |
                v
          Is low <= high?
           /           \
         Yes            No
          |              |
          v              v
    Calculate mid     Return -1
          |              |
          v              v
    Is A[mid] = target? END
       /         \
     Yes          No
      |            |
      v            v
  Return mid    Is A[mid] < target?
                    /       \
                  Yes        No
                   |          |
                   v          v
             low = mid + 1  high = mid - 1
                   |          |
                   +----+-----+
                        |
                        v
               Repeat condition
```

A graphical version should be stored in `docs/algorithm-flowcharts/` and linked here when the diagram file is added.

## 6. Source Code

The implementation is provided in [`main.cpp`](main.cpp).

The program uses:

- `low` and `high` to represent the current search interval.
- `mid` to select the middle element.
- A loop to continue searching until the target is found or the interval becomes empty.
- `-1` to indicate that the target is absent.
- Input validation to reject non-positive array sizes, invalid elements, and unsorted input.

The middle index is calculated using:

```cpp
int mid = low + (high - low) / 2;
```

This avoids the potential integer overflow associated with calculating `(low + high) / 2` for large indices.

## 7. Compilation and Execution

### Prerequisites

- A C++17-compatible compiler, such as GCC.
- A terminal or IDE such as Visual Studio Code.

### Compile

Run the following command from the experiment directory:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
```

### Execute on Windows PowerShell

```powershell
.\main.exe
```

### Execute on Linux

```bash
./main
```

## 8. Sample Execution

### Case 1: Target Found

**Input**

```text
Enter array size: 7
Enter 7 sorted integers: 5 12 18 23 31 42 57
Enter target element: 31
```

**Output**

```text
Element found at index 4.
```

### Case 2: Target Not Found

**Input**

```text
Enter array size: 5
Enter 5 sorted integers: 10 20 30 40 50
Enter target element: 25
```

**Output**

```text
Element not found.
```

### Case 3: Invalid Array Order

**Input**

```text
Enter array size: 4
Enter 4 sorted integers: 10 5 20 30
```

**Output**

```text
Error: Array must be sorted in ascending order.
```

These are expected sample results. Actual terminal screenshots should be added after local execution.

## 9. Complexity Analysis

Let `n` be the number of elements in the input array.

| Case | Description | Time complexity |
|---|---|---|
| Best | The target is at the initial midpoint | Θ(1) |
| Average | The target is found after multiple interval reductions | Θ(log n) |
| Worst | The target is absent or found after the maximum number of reductions | Θ(log n) |

### Space Complexity

| Space category | Complexity | Explanation |
|---|---|---|
| Auxiliary space of the search algorithm | Θ(1) | Only a fixed number of index variables are used. |
| Input storage | Θ(n) | The vector stores `n` elements. |
| Total storage | Θ(n) | The input array dominates the storage requirement. |

### Comparison with Linear Search

| Property | Linear search | Iterative binary search |
|---|---|---|
| Input ordering | No sorting required | Must be sorted |
| Best-case time | Θ(1) | Θ(1) |
| Worst-case time | Θ(n) | Θ(log n) |
| Auxiliary search space | Θ(1) | Θ(1) |

Binary search is generally more efficient for repeated searches over sorted arrays, particularly as the input size increases.

## 10. Test Cases

Execute the following test cases to verify the implementation.

| Test case | Input | Expected result |
|---|---|---|
| Target at the middle | `[5, 12, 18, 23, 31, 42, 57]`, target `23` | Index `3` |
| Target at the first index | `[5, 12, 18, 23, 31]`, target `5` | Index `0` |
| Target at the last index | `[5, 12, 18, 23, 31]`, target `31` | Index `4` |
| Target absent | `[10, 20, 30, 40, 50]`, target `25` | `-1` / not found |
| Single-element array, target present | `[42]`, target `42` | Index `0` |
| Single-element array, target absent | `[42]`, target `10` | Not found |
| Negative values | `[-20, -10, -5, 0, 10]`, target `-10` | Index `1` |
| Duplicate values | `[1, 2, 2, 2, 3]`, target `2` | An index containing `2` |
| Unsorted input | `[10, 5, 20, 30]` | Sorted-order error |
| Zero array size | `n = 0` | Invalid-size error |
| Invalid element input | A non-integer array element | Input error |

For arrays containing duplicate values, the implementation returns a matching index but does not guarantee the first occurrence.

## 11. Experimental Observations

The following observations are expected from the algorithm:

- The search interval decreases after each unsuccessful comparison.
- Each iteration eliminates approximately half of the remaining candidates.
- The best case occurs when the target is found at the initial midpoint.
- An absent target requires the algorithm to continue until the interval becomes empty.
- The number of comparisons grows logarithmically with the input size.
- The algorithm requires constant auxiliary space because it uses iteration instead of recursion.

Actual runtime measurements can be incorporated into the Algorithm Performance Analyzer experiment.

## 12. Limitations

- The array must be sorted in ascending order.
- The current implementation returns an arbitrary matching index when duplicates exist.
- The implementation does not sort the input automatically.
- If sorting is required before searching, its cost must be considered separately.
- The program searches for one target per execution.

## 13. Learning Outcomes

After completing this experiment, the learner should be able to:

1. Explain the divide-and-conquer principle behind binary search.
2. Implement iterative binary search in C++.
3. Use interval boundaries to control a search algorithm.
4. Analyze best-case, average-case, and worst-case complexity.
5. Explain the significance of sorted input.
6. Compare logarithmic and linear search complexity.
7. Validate input and test boundary cases.
8. Relate theoretical algorithmic complexity to practical execution.

## 14. Repository Structure

```text
03-Iterative-Binary-Search/
├── main.cpp
└── README.md
```

Supporting flowcharts and pseudocode can be maintained in the repository's shared `docs/` directories.

## 15. Conclusion

This experiment implements iterative binary search for locating a target in a sorted array. The algorithm repeatedly halves the search interval until it finds the target or determines that the target is absent.

The implementation achieves Θ(log n) average- and worst-case time complexity and Θ(1) auxiliary space. The experiment demonstrates how exploiting input structure can substantially improve search efficiency.

The implementation and test cases should be verified locally before the experiment is marked complete.

---

**Experiment status:** Documentation prepared; local execution and test verification pending.

**Next experiment:** Recursive Binary Search.