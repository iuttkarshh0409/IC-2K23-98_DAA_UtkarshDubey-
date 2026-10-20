# Experiment 01: Algorithm Fundamentals

**Course:** Design & Analysis of Algorithms Lab  
**Course Code:** IC-709 B  
**Unit:** Unit 1 — Introduction to Algorithms & Performance Analysis  
**Experiment:** Finding the Largest Element in an Array  
**Programming Language:** C++  
**Status:** Implementation and testing in progress

---

## 1. Aim

To design and implement a basic algorithm using C++, represent its logic using pseudocode and a flowchart, and analyze its time and space complexity.

## 2. Objectives

- Understand the fundamental steps involved in algorithm design.
- Translate a problem statement into a logical sequence of operations.
- Implement a linear array traversal algorithm in C++.
- Analyze best-case, average-case, and worst-case time complexity.
- Evaluate the algorithm using representative test cases.
- Understand the relationship between input size and algorithmic performance.

## 3. Problem Statement

Given an array containing `n` integers, find and display the largest element in the array.

The array may contain positive integers, negative integers, duplicate values, or a single element. The array size must be a positive integer.

### Example

**Input**
```text
Enter array size: 5
Enter 5 integers: 12 7 25 3 18
```

**Output**
```text
Largest element = 25
```

## 4. Algorithm Design

### Approach

The algorithm uses a single traversal of the array.

1. Read the number of elements, `n`.
2. Validate that `n` is positive.
3. Read the array elements.
4. Initialize `maximum` with the first array element.
5. Traverse the remaining elements.
6. If the current element is greater than `maximum`, update `maximum`.
7. After the traversal, return and display `maximum`.

Initializing the maximum with the first element ensures that the algorithm correctly handles arrays containing only negative integers.

### Pseudocode

```text
ALGORITHM FindMaximum(A, n)

    IF n <= 0 THEN
        REPORT invalid array size
        RETURN
    END IF

    maximum ← A[0]

    FOR i ← 1 TO n - 1 DO
        IF A[i] > maximum THEN
            maximum ← A[i]
        END IF
    END FOR

    RETURN maximum

END ALGORITHM
```

### Flowchart

The flowchart represents the initialization, traversal, comparison, conditional update, and termination stages of the algorithm.

**Flowchart workflow:**

```text
Start
  |
  v
Input array size n
  |
  v
Is n positive?
  | No
  +------> Display error --> End
  |
 Yes
  |
  v
Input array elements
  |
  v
maximum = A[0], i = 1
  |
  v
Is i < n?
  | No
  +------> Display maximum --> End
  |
 Yes
  |
  v
Is A[i] > maximum?
  | Yes                 | No
  v                     |
maximum = A[i]           |
  |                     |
  +----------+----------+
             |
             v
          i = i + 1
             |
             +----> Return to i < n
```

The final graphical flowchart can be stored in `docs/algorithm-flowcharts/` and linked here once generated.

## 5. Source Code

The implementation is provided in [`main.cpp`](main.cpp).

### Implementation Notes

- `findMaximum()` separates the algorithm from input/output operations.
- The array is passed by constant reference to avoid copying it.
- The algorithm uses constant auxiliary space.
- The input size is validated before allocating the vector.
- Invalid array elements are rejected.
- The implementation uses standard C++ library facilities and requires no external dependencies.

## 6. Compilation and Execution

### Prerequisites

- A C++ compiler supporting C++17 or later, such as GCC.
- A terminal or integrated development environment such as VS Code.

### Compile

Run the following command from this experiment's directory:

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

### Sample Execution

```text
Enter array size: 5
Enter 5 integers: 12 7 25 3 18
Largest element = 25
```

## 7. Complexity Analysis

Let `n` represent the number of elements in the array.

### Time Complexity

The algorithm initializes the maximum using the first element and then examines each of the remaining `n - 1` elements.

The number of comparisons between array elements is exactly `n - 1`.

| Case | Description | Time Complexity |
|---|---|---|
| Best case | Any valid array, including an array with equal elements | Θ(n) |
| Average case | Any distribution of array values | Θ(n) |
| Worst case | Any distribution of array values | Θ(n) |

Unlike some searching algorithms, the execution time does not improve when the largest element appears early. Every element must be examined to establish the maximum.

### Space Complexity

| Space category | Complexity | Explanation |
|---|---|---|
| Auxiliary space | O(1) | Only a fixed number of additional variables are used by the algorithm. |
| Input storage | O(n) | The input array contains `n` elements. |
| Total storage | O(n) | The array dominates the overall storage requirement. |

## 8. Test Cases

The following cases define the expected behavior of the program. Mark each case as verified only after executing it.

| Test | Input array | Expected output |
|---|---|---|
| Ordinary input | `[12, 7, 25, 3, 18]` | `25` |
| Single element | `[42]` | `42` |
| All negative values | `[-8, -2, -15, -4]` | `-2` |
| All equal values | `[6, 6, 6, 6]` | `6` |
| Maximum at the end | `[1, 2, 3, 4, 99]` | `99` |
| Maximum at the beginning | `[99, 4, 3, 2, 1]` | `99` |
| Zero array size | `n = 0` | Error message and nonzero exit status |
| Negative array size | `n = -3` | Error message and nonzero exit status |
| Invalid array element | Non-integer element | Error message and nonzero exit status |

### Test Results

Test execution results and screenshots should be added after running the program locally. Expected results in this table are not a substitute for actual execution evidence.

## 9. Correctness Explanation

Initially, `maximum` is assigned the first array element. Therefore, it is the largest element among the elements processed so far.

During each iteration, the algorithm compares the current element with `maximum`. If the current element is larger, the algorithm updates `maximum`. Otherwise, the current value of `maximum` remains unchanged.

After processing each element, `maximum` is the largest value among all elements examined so far.

When the loop terminates, every array element has been examined. Consequently, `maximum` is the largest element in the entire array.

Thus, the algorithm correctly solves the problem for every non-empty integer array.

## 10. Experimental Observations

The following observations are theoretical and should be compared with the actual execution results.

- The algorithm examines every element exactly once after initialization.
- The number of element comparisons increases linearly with the input size.
- The execution time is Θ(n) in the best, average, and worst cases.
- The algorithm handles negative values correctly because initialization uses the first element rather than zero.
- The algorithm does not modify the input array.
- The measured runtime may vary because of compiler optimizations, hardware, operating-system scheduling, and measurement overhead.

Large-scale benchmarking is not required to establish the correctness of this introductory implementation. Systematic performance measurements will be developed in the Algorithm Performance Analyzer experiment.

## 11. Limitations

- The algorithm requires a non-empty array.
- The implementation assumes array elements are representable by the C++ `int` type.
- The algorithm finds only the maximum value, not every index at which it occurs.
- The implementation does not measure execution time independently.

These limitations are acceptable for the stated problem and can be addressed in more advanced experiments if needed.

## 12. Learning Outcomes

After completing this experiment, the learner should be able to:

1. Translate a simple problem into an algorithm.
2. Represent algorithm logic using pseudocode and flowcharts.
3. Implement a linear traversal algorithm in C++.
4. Explain the correctness of an algorithm using a loop invariant.
5. Calculate time and space complexity.
6. Distinguish between theoretical complexity and measured execution time.
7. Design test cases for ordinary, boundary, and invalid inputs.
8. Organize source code and supporting documentation in a Git repository.

## 13. Repository Structure

```text
01-Algorithm-Fundamentals/
├── main.cpp
└── README.md
```

Supporting flowcharts, pseudocode, and complexity documentation can additionally be maintained in the repository's shared `docs/` directories.

## 14. Conclusion

The experiment demonstrates a basic algorithm for finding the largest element in an array through linear traversal. The implementation illustrates algorithm design, input validation, correctness reasoning, and asymptotic complexity analysis.

The algorithm runs in Θ(n) time and uses O(1) auxiliary space. Its correctness and expected behavior should be confirmed through the specified test cases before the experiment is marked complete.

---

**Experiment status:** Documentation prepared; local execution and test verification pending.

**Next experiment:** Basic Array Operations.