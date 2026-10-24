# Experiment 02: Preorder Traversal of a Binary Tree

## Aim
To implement preorder traversal of a Binary Search Tree (BST) using C++.

## Problem Statement
Create a Binary Search Tree by inserting integer values and traverse it using the preorder technique. Preorder traversal visits the root node first, followed by the left subtree and then the right subtree.

## Traversal Order

**Root → Left → Right**

## Algorithm
1. Create a Binary Search Tree by inserting the input values.
2. Start preorder traversal from the root node.
3. If the current node is empty, return.
4. Visit and display the current node's value.
5. Recursively traverse the left subtree.
6. Recursively traverse the right subtree.
7. Stop when all nodes have been visited.

## Pseudocode
```text
PREORDER(root):
    If root is empty:
        Return

    Display root.data
    PREORDER(root.left)
    PREORDER(root.right)
```

## Sample Input
```text
7
50 30 70 20 40 60 80
```

## Sample Output
```text
Preorder traversal (Root, Left, Right): 50 30 20 40 70 60 80
```

## Complexity Analysis

Let `n` be the number of nodes and `h` be the height of the tree.

- **Time Complexity:** O(n), because every node is visited once.
- **Auxiliary Space Complexity:** O(h), due to recursive function calls.
- **Worst-case Auxiliary Space:** O(n), when the tree is skewed.
- **Tree Storage:** O(n), for the array-based node representation.

## Test Cases
1. **Balanced BST:** Verify preorder output for a tree with left and right subtrees.
2. **Single node:** Verify that the root is displayed once.
3. **Ascending insertion order:** Verify traversal of a right-skewed tree.
4. **Descending insertion order:** Verify traversal of a left-skewed tree.
5. **Duplicate values:** Verify that duplicate values are ignored.
6. **Invalid node count:** Verify that unsupported input sizes are rejected.

## Learning Outcomes
- Understood the preorder traversal technique.
- Implemented recursive tree traversal.
- Learned the difference between visiting the root first and visiting it later.
- Analyzed traversal time and auxiliary space complexity.

## Note
This experiment uses a Binary Search Tree to construct the input tree. Preorder traversal itself can be applied to any binary tree; it does not require the BST ordering property.
