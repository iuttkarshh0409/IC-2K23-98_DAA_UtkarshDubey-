# Experiment 05: Recursive Tree Traversal

## Aim
To implement preorder, inorder, and postorder traversal of a Binary Search Tree (BST) using recursion in C++.

## Problem Statement
Construct a Binary Search Tree by inserting integer values and traverse the tree using three recursive traversal techniques: preorder, inorder, and postorder.

## Traversal Orders

| Traversal | Visiting Order |
|---|---|
| Preorder | Root → Left → Right |
| Inorder | Left → Root → Right |
| Postorder | Left → Right → Root |

## Algorithm
1. Initialize an empty Binary Search Tree.
2. Read the number of nodes and their integer values.
3. Insert each value according to the BST ordering property.
4. Perform preorder traversal by visiting the root, then the left subtree, and finally the right subtree.
5. Perform inorder traversal by visiting the left subtree, then the root, and finally the right subtree.
6. Perform postorder traversal by visiting the left subtree, then the right subtree, and finally the root.
7. Display the results of all three traversals.

## Pseudocode
```text
PREORDER(root):
    If root is empty:
        Return
    Display root.data
    PREORDER(root.left)
    PREORDER(root.right)

INORDER(root):
    If root is empty:
        Return
    INORDER(root.left)
    Display root.data
    INORDER(root.right)

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
Preorder  (Root, Left, Right): 50 30 20 40 70 60 80
Inorder   (Left, Root, Right): 20 30 40 50 60 70 80
Postorder (Left, Right, Root): 20 40 30 60 80 70 50
```

## Complexity Analysis

Let `n` be the number of nodes and `h` be the height of the tree.

- **Time Complexity:** O(n) for each traversal because every node is visited once.
- **Auxiliary Space Complexity:** O(h), due to recursive function calls.
- **Worst-case Auxiliary Space:** O(n), when the tree is skewed.
- **Tree Storage:** O(n), for the array-based node representation.

## Test Cases
1. **Single node:** All three traversals should display the same value.
2. **Balanced BST:** Verify all three traversal sequences.
3. **Ascending insertion order:** Test a right-skewed tree.
4. **Descending insertion order:** Test a left-skewed tree.
5. **Duplicate values:** Verify that duplicates are ignored.
6. **Invalid node count:** Verify that unsupported input sizes are rejected.

## Learning Outcomes
- Understood the three fundamental binary-tree traversal techniques.
- Implemented recursive tree traversal in C++.
- Compared the visiting order of preorder, inorder, and postorder.
- Learned how recursion explores left and right subtrees.
- Analyzed traversal time and auxiliary space complexity.

## Note
This experiment uses a Binary Search Tree as the input structure. The three traversal algorithms themselves can be applied to any binary tree, regardless of its ordering property.
