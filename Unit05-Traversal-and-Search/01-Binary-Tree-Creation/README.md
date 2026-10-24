# Experiment 01: Binary Tree Creation

## Aim
To create a Binary Search Tree (BST) using C++ and display its elements using inorder traversal.

## Problem Statement
Write a C++ program to construct a Binary Search Tree by inserting integer values. For each node, values smaller than the node are placed in the left subtree, and values greater than the node are placed in the right subtree. Duplicate values are not inserted.

## Algorithm
1. Initialize an empty tree.
2. Read the number of nodes to insert.
3. Read each integer value.
4. If the tree is empty, create the root node.
5. If the value is smaller than the current node, insert it into the left subtree.
6. If the value is greater than the current node, insert it into the right subtree.
7. If the value already exists, report the duplicate and do not insert it.
8. Display the total number of nodes.
9. Perform inorder traversal to display the stored values in ascending order.

## Pseudocode
```text
INSERT(root, value):
    If root is empty:
        Create and return a new node

    If value < root.data:
        Insert value into left subtree

    Else if value > root.data:
        Insert value into right subtree

    Else:
        Report duplicate value

    Return root

INORDER(root):
    If root is empty:
        Return

    INORDER(root.left)
    Display root.data
    INORDER(root.right)
```

## Sample Input
```text
7
50 30 70 20 40 60 80
```

## Sample Output
```text
Binary Search Tree created successfully.
Number of nodes: 7
Inorder traversal: 20 30 40 50 60 70 80
```

## Complexity Analysis

Let `n` be the number of inserted nodes and `h` be the height of the tree.

- **Insertion:** O(h) per value.
- **Average insertion time:** O(log n) per value for a reasonably balanced tree.
- **Worst-case insertion time:** O(n) per value for a completely skewed tree.
- **Building the tree:** O(n log n) on average; O(n²) in the worst case.
- **Inorder traversal:** O(n).
- **Space complexity:** O(n) for storing nodes, with up to O(h) recursive call-stack space.

The implementation uses a fixed-size array of 100 nodes, so its maximum supported capacity is 100.

## Test Cases
1. **Seven distinct values:** Verify that all nodes are inserted and displayed in ascending order.
2. **Single node:** Insert one value and verify that it becomes the root.
3. **Ascending values:** Verify insertion into a right-skewed tree.
4. **Descending values:** Verify insertion into a left-skewed tree.
5. **Duplicate values:** Verify that duplicates are rejected without increasing the node count.
6. **Invalid node count:** Verify that values outside the supported range are rejected.

## Learning Outcomes
- Understood the structure of a Binary Search Tree.
- Implemented recursive insertion.
- Learned how the BST ordering property works.
- Used inorder traversal to display values in sorted order.
- Analyzed average-case and worst-case time complexity.

## Note
A Binary Search Tree is a special type of binary tree that maintains an ordering property. This experiment uses BST insertion as the chosen implementation of binary-tree creation.
