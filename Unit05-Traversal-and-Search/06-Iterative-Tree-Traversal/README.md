# Experiment 06: Iterative Tree Traversal

## Aim
To implement preorder, inorder, and postorder traversal of a Binary Search Tree (BST) iteratively using stacks in C++.

## Problem Statement
Write a C++ program to construct a Binary Search Tree and traverse it without using recursive traversal functions. Implement the following traversal techniques:
- **Preorder:** Root → Left → Right
- **Inorder:** Left → Root → Right
- **Postorder:** Left → Right → Root

## Algorithm

### 1. Construct the BST
1. Read the number of nodes and their values.
2. Insert each value according to BST properties.
3. Ignore duplicate values.
4. Store nodes in a fixed-size array.

### 2. Iterative Preorder Traversal
1. Push the root onto a stack.
2. Pop and visit the top node.
3. Push its right child, then its left child.
4. Repeat until the stack is empty.

### 3. Iterative Inorder Traversal
1. Start at the root.
2. Push nodes while moving towards the leftmost child.
3. Pop and visit a node.
4. Move to its right child and repeat until no nodes or stack entries remain.

### 4. Iterative Postorder Traversal
1. Push the root onto the first stack.
2. Pop a node and push it onto the second stack.
3. Push its left and right children onto the first stack when they exist.
4. Pop and visit all nodes from the second stack.

## Pseudocode

```text
ITERATIVE_PREORDER(root)
    if root is NULL, return
    push root onto stack

    while stack is not empty
        node = pop stack
        visit node
        if node.right exists, push node.right
        if node.left exists, push node.left

ITERATIVE_INORDER(root)
    current = root

    while current exists OR stack is not empty
        while current exists
            push current onto stack
            current = current.left

        current = pop stack
        visit current
        current = current.right

ITERATIVE_POSTORDER(root)
    push root onto stack1

    while stack1 is not empty
        node = pop stack1
        push node onto stack2
        if node.left exists, push node.left
        if node.right exists, push node.right

    while stack2 is not empty
        visit pop(stack2)
```

## Sample Input

```text
7
50 30 70 20 40 60 80
```

## Sample Output

```text
Preorder (iterative): 50 30 20 40 70 60 80
Inorder (iterative): 20 30 40 50 60 70 80
Postorder (iterative): 20 40 30 60 80 70 50
```

## Complexity Analysis

Let \(n\) be the number of nodes and \(h\) the height of the tree.

| Traversal | Time Complexity | Auxiliary Space |
|---|---|---|
| Preorder | \(O(n)\) | \(O(n)\) worst case |
| Inorder | \(O(n)\) | \(O(n)\) worst case |
| Postorder | \(O(n)\) | \(O(n)\) for two stacks |

Each traversal visits every node exactly once. Iterative traversal uses explicit stacks instead of the program's recursive call stack.

## Edge Cases
- A tree containing a single node.
- A sorted input sequence that produces a skewed BST.
- Duplicate values.
- A tree with both left and right subtrees.
- An invalid node count outside the supported range.

## Learning Outcomes
- Understood the role of stacks in iterative tree traversal.
- Implemented preorder, inorder, and postorder without recursive traversal functions.
- Compared iterative traversal with recursive traversal.
- Analyzed time and auxiliary-space complexity.

## Conclusion
The program successfully performs all three binary tree traversals iteratively using fixed-size arrays and stacks, avoiding recursive traversal calls.
