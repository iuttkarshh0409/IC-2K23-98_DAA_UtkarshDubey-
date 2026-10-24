# Experiment 04: Postorder Traversal of a Binary Tree

## Aim
To implement postorder traversal of a Binary Search Tree (BST) using C++.

## Problem Statement
Create a Binary Search Tree by inserting integer values and traverse it using the postorder technique. Postorder traversal visits the left subtree first, then the right subtree, and finally the root node.

## Traversal Order

**Left → Right → Root**

## Algorithm
1. Create a Binary Search Tree using the input values.
2. Start postorder traversal from the root node.
3. If the current node is empty, return.
4. Recursively traverse the left subtree.
5. Recursively traverse the right subtree.
6. Visit and display the current node's value.
7. Stop when all nodes have been visited.

## Pseudocode
```text
POSTORDER(root):
    If root is empty:
        Return

    POSTORDER(root.left)
    POSTORDER(root.right)
    Display root.data
```

## Sample Input
```text
7
50 30 70 20 40 60 80
```

## Sample Output
```text
Postorder traversal (Left, Right, Root): 20 40 30 60 80 70 50
```

## Complexity Analysis

Let `n` be the number of nodes and `h` be the height of the tree.

- **Time Complexity:** O(n), because every node is visited exactly once.
- **Auxiliary Space Complexity:** O(h), due to recursive function calls.
- **Worst-case Auxiliary Space:** O(n), when the tree is skewed.
- **Tree Storage:** O(n), for the array-based node representation.

## Test Cases
1. **Single node:** Verify that the only node is displayed once.
2. **Left-skewed tree:** Verify that nodes are visited from the deepest left node back toward the root.
3. **Right-skewed tree:** Verify that nodes are visited from the deepest right node back toward the root.
4. **Mixed insertion order:** Verify the expected postorder sequence.
5. **Duplicate values:** Verify that duplicate values are ignored.
6. **Invalid node count:** Verify that unsupported input sizes are rejected.

## Learning Outcomes
- Understood the postorder traversal technique.
- Implemented recursive traversal of a binary tree.
- Learned why the root is visited after both subtrees.
- Analyzed traversal time and auxiliary space complexity.

## Note
Postorder traversal can be applied to any binary tree. This implementation constructs a Binary Search Tree as its input structure.
