# Experiment 03: Inorder Traversal of a Binary Tree

## Aim
To implement inorder traversal of a Binary Search Tree (BST) using C++.

## Problem Statement
Create a Binary Search Tree by inserting integer values and traverse it using the inorder technique. Inorder traversal visits the left subtree first, followed by the root node, and then the right subtree.

## Traversal Order

**Left → Root → Right**

## Algorithm
1. Create a Binary Search Tree using the input values.
2. Start inorder traversal from the root node.
3. If the current node is empty, return.
4. Recursively traverse the left subtree.
5. Visit and display the current node's value.
6. Recursively traverse the right subtree.
7. Stop when all nodes have been visited.

## Pseudocode
```text id="h4pv1x"
INORDER(root):
    If root is empty:
        Return

    INORDER(root.left)
    Display root.data
    INORDER(root.right)
```

## Sample Input
```text id="3kbvji"
7
50 30 70 20 40 60 80
```

## Sample Output
```text id="j1az1p"
Inorder traversal (Left, Root, Right): 20 30 40 50 60 70 80
```

## Complexity Analysis

Let `n` be the number of nodes and `h` be the height of the tree.

- **Time Complexity:** O(n), because every node is visited exactly once.
- **Auxiliary Space Complexity:** O(h), due to recursive function calls.
- **Worst-case Auxiliary Space:** O(n), when the tree is skewed.
- **Tree Storage:** O(n), for the array-based node representation.

## Test Cases
1. **Single node:** Verify that the only node is displayed once.
2. **Ascending insertion order:** Verify that values appear in ascending order.
3. **Descending insertion order:** Verify that values still appear in ascending order.
4. **Mixed insertion order:** Verify the correct inorder sequence.
5. **Duplicate values:** Verify that duplicate values are ignored.
6. **Invalid node count:** Verify that unsupported input sizes are rejected.

## Learning Outcomes
- Understood the inorder traversal technique.
- Implemented recursive traversal of a binary tree.
- Learned that inorder traversal of a BST produces values in sorted order.
- Analyzed traversal time and auxiliary space complexity.

## Note
Inorder traversal can be applied to any binary tree. The property of producing sorted output applies specifically to a Binary Search Tree with the ordering property maintained.
