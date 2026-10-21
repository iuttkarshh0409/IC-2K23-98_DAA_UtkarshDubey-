# Experiment 04: Recursive Binary Search

**Course:** Design & Analysis of Algorithms Lab  
**Course Code:** IC-709 B  
**Unit:** Unit 1 — Introduction to Algorithms & Performance Analysis  
**Experiment:** Recursive Binary Search  
**Programming Language:** C++17  
**Status:** Implementation and testing in progress

---

## 1. Aim

To implement recursive binary search in C++ to locate a target element in a sorted array and analyze its time and space complexity.

## 2. Objectives

- Understand recursion and recursive function calls.
- Implement binary search using a recursive approach.
- Identify the base case and recursive cases.
- Understand how the search interval is reduced during each recursive call.
- Validate the sorted-order requirement of the input array.
- Analyze best-case, average-case, and worst-case complexity.
- Compare recursive binary search with iterative binary search.

## 3. Problem Statement

Given an array of `n` integers sorted in ascending order and a target value, determine whether the target exists in the array.

If the target is present, return its index. Otherwise, return `-1`.

The solution must use recursion rather than a loop to perform the binary search.

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

Recursive binary search divides the current search interval into two halves and calls the same function on the relevant half.

The algorithm uses two important cases:

**Base case:** If `low > high`, the search interval is empty and the target is absent. Return `-1`.

**Recursive cases:**

1. Calculate the middle index.
2. If the middle element equals the target, return its index.
3. If the target is greater than the middle element, recursively search the right half.
4. Otherwise, recursively search the left half.

The input array must be sorted in ascending order.

### Pseudocode

```text
ALGORITHM RecursiveBinarySearch(A, low, high, target)

    IF low > high THEN
        RETURN -1
    END IF

    mid ← low + floor((high - low) / 2)

    IF A[mid] = target THEN
        RETURN mid

    ELSE IF A[mid] < target THEN
        RETURN RecursiveBinarySearch(
            A, mid + 1, high, target
        )

    ELSE
        RETURN RecursiveBinarySearch(
            A, low, mid - 1, target
        )
    END IF

END ALGORITHM
```

### Initial Function Call

For an array of `n` elements, the initial call is:

```cpp
recursiveBinarySearch(arr, 0, n - 1, target);
```

The function continues calling itself with a smaller search interval until the target is found or the base case is reached.

## 5. Flowchart

The algorithm follows this logical flow:

```text
                START
                  |
                  v
        Input sorted array
        and target element
                  |
                  v
        Call recursive search
                  |
                  v
            Is low > high?
             /          \
           Yes           No
            |             |
            v             v
        Return -1      Calculate mid
                          |
                          v
                  Is A[mid] = target?
                     /          \
                   Yes           No
                    |             |
                    v             v
                Return mid   Is A[mid] < target?
                               /           \
                             Yes            No
                              |              |
                              v              v
                        Search right    Search left
                           half            half
                              \              /
                               \            /
                                Recursive
                                 call
```

The graphical flowchart should be saved in `docs/algorithm-flowcharts/` and linked here once the diagram file is available.

## 6. Source Code

The complete implementation is provided in [`main.cpp`](main.cpp).

The implementation uses the following components:

- `recursiveBinarySearch()` performs the recursive search.
- `low` and `high` define the current search interval.
- `mid` identifies the middle element.
- The base case terminates the recursion when the interval becomes empty.
- The function returns an index when the target is found and `-1` otherwise.
- The main function validates the input size, array elements, and ascending order.

The middle index is calculated using:

```cpp
int mid = low + (high - low) / 2;
```

This avoids the potential integer overflow associated with calculating `(low + high) / 2` for large indices.

## 7. Compilation and Execution

### Prerequisites

- A C++17-compatible compiler, such as GCC.
- A terminal or an IDE such as Visual Studio Code.

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

These are illustrative expected results. Actual execution screenshots should be captured after running the program locally.

## 9. Complexity Analysis

Let `n` denote the number of elements in the array.

### Time Complexity

| Case | Description | Time complexity |
|---|---|---|
| Best | Target is found at the initial midpoint | Θ(1) |
| Average | Multiple recursive calls are required | Θ(log n) |
| Worst | Target is absent or found after the maximum number of interval reductions | Θ(log n) |

Each recursive call reduces the search interval to approximately half its previous size.

The recurrence for the worst-case running time is:

\[
T(n) = T(n/2) + \Theta(1)
\]

Solving this recurrence gives:

\[
T(n) = \Theta(\log n)
\]

### Space Complexity

| Space category | Complexity | Explanation |
|---|---|---|
| Best-case auxiliary space | Θ(1) | The target is found in the first call. |
| Average-case auxiliary space | O(log n) | Recursive calls occupy stack frames. |
| Worst-case auxiliary space | O(log n) | The recursion depth grows logarithmically. |
| Input storage | Θ(n) | The input array stores `n` elements. |

Unlike iterative binary search, recursive binary search requires additional call-stack space.

## 10. Comparison with Iterative Binary Search

| Property | Iterative binary search | Recursive binary search |
|---|---|---|
| Control mechanism | Loop | Recursive function calls |
| Base case | Loop termination condition | `low > high` |
| Best-case time | Θ(1) | Θ(1) |
| Average-case time | Θ(log n) | Θ(log n) |
| Worst-case time | Θ(log n) | Θ(log n) |
| Auxiliary space | Θ(1) | O(log n) |
| Function-call overhead | No recursive calls | Recursive call overhead |
| Main advantage | Lower auxiliary space | Clearly expresses recursive decomposition |

Both implementations perform the same fundamental search operation and have logarithmic average- and worst-case time complexity.

## 11. Test Cases

Execute the following test cases to verify the implementation.

| Test case | Input | Expected result |
|---|---|---|
| Target at the midpoint | `[5, 12, 18, 23, 31, 42, 57]`, target `23` | Index `3` |
| Target at the first index | `[5, 12, 18, 23, 31]`, target `5` | Index `0` |
| Target at the last index | `[5, 12, 18, 23, 31]`, target `31` | Index `4` |
| Target absent | `[10, 20, 30, 40, 50]`, target `25` | `-1` / not found |
| Single-element array, target present | `[42]`, target `42` | Index `0` |
| Single-element array, target absent | `[42]`, target `10` | Not found |
| Negative values | `[-20, -10, -5, 0, 10]`, target `-10` | Index `1` |
| Duplicate values | `[1, 2, 2, 2, 3]`, target `2` | An index containing `2` |
| Unsorted input | `[10, 5, 20, 30]` | Sorted-order error |
| Zero array size | `n = 0` | Invalid-size error |
| Invalid element input | Non-integer array element | Input error |

For duplicate values, the implementation returns a matching index but does not guarantee the first occurrence.

## 12. Experimental Observations

The expected observations are:

- Each recursive call reduces the search interval.
- The base case prevents further recursion when no candidates remain.
- The search requires logarithmically many recursive calls in the worst case.
- Recursive binary search and iterative binary search have equivalent asymptotic time complexity.
- Recursive binary search uses additional stack space.
- Input validation ensures that the binary search precondition is satisfied.

Actual execution results should be documented after local testing.

## 13. Limitations

- The input array must be sorted in ascending order.
- Recursive calls introduce stack overhead.
- The implementation returns an arbitrary matching index when duplicates exist.
- The program does not sort the input automatically.
- The program searches for one target per execution.

## 14. Learning Outcomes

After completing this experiment, the learner should be able to:

1. Explain recursion and its role in algorithm design.
2. Implement recursive binary search in C++.
3. Identify base cases and recursive cases.
4. Explain how recursive calls reduce the search interval.
5. Analyze logarithmic time complexity.
6. Evaluate auxiliary stack-space requirements.
7. Compare iterative and recursive implementations.
8. Validate input and test boundary conditions.

## 15. Repository Structure

```text
04-Recursive-Binary-Search/
├── main.cpp
└── README.md
```

Supporting flowcharts, pseudocode, and complexity documentation can be maintained in the repository's shared `docs/` directories.

## 16. Conclusion

This experiment implements recursive binary search to locate a target in a sorted array. The algorithm repeatedly reduces the search interval through recursive function calls until the target is found or the interval becomes empty.

The implementation achieves Θ(log n) average- and worst-case time complexity and O(log n) worst-case auxiliary stack space. It demonstrates the relationship between recursion, algorithmic efficiency, and memory usage.

The implementation and test cases should be verified locally before the experiment is marked complete.

---

**Experiment status:** Documentation prepared; local execution and test verification pending.

**Next milestone:** Algorithm Performance Analyzer.