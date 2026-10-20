# Experiment 02: Basic Array Operations

**Course:** Design & Analysis of Algorithms Lab  
**Course Code:** IC-709 B  
**Unit:** Unit 1 — Introduction to Algorithms & Performance Analysis  
**Experiment:** Basic Array Operations  
**Programming Language:** C++17  
**Status:** Implementation and testing in progress

---

## 1. Aim

To implement fundamental array operations in C++ and analyze their time and space complexity.

## 2. Objectives

- Understand the representation and manipulation of arrays.
- Implement array traversal and display.
- Insert an element at a specified position.
- Delete an element from a specified position.
- Search for an element using linear search.
- Update an element at a specified position.
- Validate input and handle invalid positions.
- Analyze the time and space complexity of each operation.

## 3. Problem Statement

Design and implement a menu-driven C++ program that performs basic operations on an integer array.

The program must support:

1. Displaying array elements.
2. Inserting an element at a specified position.
3. Deleting an element from a specified position.
4. Searching for an element.
5. Updating an element at a specified position.
6. Exiting the program.

The implementation uses a fixed-capacity array with a maximum capacity of 100 elements. Array positions are zero-based, and the logical size is maintained separately from the allocated capacity.

## 4. Algorithm Design

### 4.1 Array Traversal and Display

Traverse the array from index `0` to `size - 1` and display each element.

**Pseudocode**

```text
ALGORITHM Display(A, size)

    IF size = 0 THEN
        PRINT "Array is empty"
        RETURN
    END IF

    FOR i ← 0 TO size - 1 DO
        PRINT A[i]
    END FOR

END ALGORITHM
```

### 4.2 Insertion

Insert a new value at the specified zero-based position. Shift existing elements one position to the right to create space.

Valid positions range from `0` to `size`, inclusive. Insertion is rejected if the array is full.

**Pseudocode**

```text
ALGORITHM Insert(A, size, capacity, position, value)

    IF size = capacity THEN
        PRINT "Array is full"
        RETURN
    END IF

    IF position < 0 OR position > size THEN
        PRINT "Invalid position"
        RETURN
    END IF

    FOR i ← size DOWNTO position + 1 DO
        A[i] ← A[i - 1]
    END FOR

    A[position] ← value
    size ← size + 1

END ALGORITHM
```

### 4.3 Deletion

Delete the element at the specified position. Shift all subsequent elements one position to the left and decrease the logical size.

**Pseudocode**

```text
ALGORITHM Delete(A, size, position)

    IF position < 0 OR position >= size THEN
        PRINT "Invalid position"
        RETURN
    END IF

    FOR i ← position TO size - 2 DO
        A[i] ← A[i + 1]
    END FOR

    size ← size - 1

END ALGORITHM
```

### 4.4 Linear Search

Compare the target value with each array element. Return the first matching index, or `-1` if the target is absent.

**Pseudocode**

```text
ALGORITHM Search(A, size, target)

    FOR i ← 0 TO size - 1 DO
        IF A[i] = target THEN
            RETURN i
        END IF
    END FOR

    RETURN -1

END ALGORITHM
```

### 4.5 Updating an Element

Replace the element at a valid index with the specified value.

**Pseudocode**

```text
ALGORITHM Update(A, size, position, value)

    IF position < 0 OR position >= size THEN
        PRINT "Invalid position"
        RETURN
    END IF

    A[position] ← value

END ALGORITHM
```

## 5. Flowchart

The overall program follows a menu-driven control flow.

```text
             START
               |
               v
       Read initial array
               |
               v
        Display menu
               |
               v
         Read choice
               |
               v
      +------------------+
      | Switch on choice |
      +------------------+
        |   |   |   |   |
        v   v   v   v   v
      Show Insert Delete Search Update
        |   |   |   |   |
        +---+---+---+---+
               |
               v
       Is choice zero?
          |       |
         No      Yes
          |       |
          v       v
    Display menu  END
```

Each operation performs its own validation before modifying the array.

A graphical flowchart should be saved in the repository's `docs/algorithm-flowcharts/` directory and linked here when the diagram asset is available.

## 6. Source Code

The complete implementation is provided in [`main.cpp`](main.cpp).

The program uses separate functions for display, insertion, deletion, searching, and updating. This modular design makes the implementation easier to understand, test, and maintain.

Key implementation details:

- `CAPACITY` defines the maximum array capacity.
- `size` tracks the number of currently stored elements.
- Insertion shifts elements to the right.
- Deletion shifts elements to the left.
- Linear search returns the first matching index.
- Updating uses direct indexed assignment.
- Invalid positions and invalid input are handled with error messages.

## 7. Compilation and Execution

### Prerequisites

- A C++17-compatible compiler, such as GCC.
- A terminal or an IDE such as Visual Studio Code.

### Compile

Run this command from the experiment directory:

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

The following is the expected interaction for a sequence of operations.

### Initial Input

```text
Enter initial array size (0-100): 5
Enter 5 elements: 10 20 30 40 50
```

### Insert an Element

```text
Enter choice: 2
Enter zero-based insertion position and value: 2 25
Element inserted successfully.
```

Result:

```text
10 20 25 30 40 50
```

### Delete an Element

```text
Enter choice: 3
Enter zero-based deletion position: 3
Element deleted successfully.
```

Result:

```text
10 20 25 40 50
```

### Search for an Element

```text
Enter choice: 4
Enter value to search: 40
Element found at index 3.
```

### Update an Element

```text
Enter choice: 5
Enter zero-based position and new value: 0 99
Element updated successfully.
```

Result:

```text
99 20 25 40 50
```

**Note:** These are illustrative expected results. Actual execution screenshots and test outcomes must be recorded after running the program locally.

## 9. Complexity Analysis

Let `n` denote the current logical size of the array.

| Operation | Best case | Average case | Worst case | Auxiliary space |
|---|---|---|---|---|
| Display | Θ(n) | Θ(n) | Θ(n) | Θ(1) |
| Insertion | Θ(1) | Θ(n) | Θ(n) | Θ(1) |
| Deletion | Θ(1) | Θ(n) | Θ(n) | Θ(1) |
| Linear search | Θ(1) | Θ(n) | Θ(n) | Θ(1) |
| Update by index | Θ(1) | Θ(1) | Θ(1) | Θ(1) |

### Explanation

**Display:** Every stored element must be visited, so the running time is Θ(n).

**Insertion:** Inserting at the end requires no shifting, giving Θ(1) time when capacity is available. Inserting near the beginning requires shifting many elements, giving Θ(n) worst-case time.

**Deletion:** Deleting the last element requires no shifting, giving Θ(1) time. Deleting the first element requires shifting the remaining elements, giving Θ(n) worst-case time.

**Linear search:** The first element may match the target, giving Θ(1) best-case time. If the target is absent or appears last, all elements may be examined, giving Θ(n) worst-case time.

**Update:** A valid index directly identifies the element, so updating its value takes Θ(1) time.

The array occupies Θ(1) auxiliary space beyond its fixed allocation. The program allocates a fixed-capacity array of 100 integers, independent of the current logical size.

## 10. Test Cases

The following cases should be executed to verify the implementation.

| Test case | Operation | Expected result |
|---|---|---|
| Display a non-empty array | Display | All elements displayed in order |
| Display an empty array | Display | Array-empty message |
| Insert at index `0` | Insertion | New element becomes the first element |
| Insert at index `size` | Insertion | New element becomes the last element |
| Insert at a middle index | Insertion | Elements shift right correctly |
| Insert at an invalid index | Insertion | Error message; array unchanged |
| Insert when full | Insertion | Error message; array unchanged |
| Delete at index `0` | Deletion | First element removed |
| Delete at index `size - 1` | Deletion | Last element removed |
| Delete from a middle index | Deletion | Remaining elements shift left |
| Delete from an empty array | Deletion | Invalid-position message |
| Search for an existing value | Search | First matching index returned |
| Search for a missing value | Search | Element-not-found message |
| Update a valid index | Update | Specified value replaced |
| Update an invalid index | Update | Error message; array unchanged |
| Enter an invalid menu choice | Menu | Invalid-choice message |

## 11. Experimental Observations

The expected observations are:

- Traversal takes linear time because every element is visited.
- Insertion and deletion require element shifting when performed away from the end.
- Linear search works on both sorted and unsorted arrays.
- Updating an element by index takes constant time.
- The logical size changes after successful insertion and deletion.
- Boundary validation prevents invalid array positions from being accessed.
- The fixed-capacity implementation cannot exceed 100 stored elements.

Actual experimental observations should be updated after the program has been compiled and tested.

## 12. Limitations

- The array has a fixed maximum capacity of 100 elements.
- Insertion and deletion may require shifting multiple elements.
- Linear search returns only the first occurrence of a matching value.
- Positions are zero-based, which must be understood when supplying input.
- The program does not resize its allocated array dynamically.
- The current experiment does not benchmark execution time across different input sizes.

## 13. Learning Outcomes

After completing this experiment, the learner should be able to:

1. Implement fundamental array operations in C++.
2. Explain insertion and deletion through element shifting.
3. Implement linear search for an unsorted array.
4. Update elements through direct indexing.
5. Validate positions and handle array boundary conditions.
6. Analyze best-case, average-case, and worst-case complexity.
7. Organize an algorithm into modular functions.
8. Relate algorithmic operations to their theoretical time and space costs.

## 14. Repository Structure

```text
02-Array-Operations/
├── main.cpp
└── README.md
```

Supporting pseudocode, graphical flowcharts, and other shared documentation can be stored in the repository's `docs/` directories.

## 15. Conclusion

This experiment demonstrates the fundamental operations performed on arrays through a modular, menu-driven C++ program. It illustrates traversal, insertion, deletion, linear searching, updating, and input validation.

The experiment also establishes the relationship between an operation's implementation and its asymptotic complexity, particularly the element shifting required for insertion and deletion.

The implementation and test cases should be verified locally before the experiment is marked complete.

---

**Experiment status:** README prepared; execution and test verification pending.

**Next experiment:** Iterative Binary Search.