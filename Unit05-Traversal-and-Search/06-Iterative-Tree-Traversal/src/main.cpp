
#include <iostream>
using namespace std;

const int MAX_NODES = 100;

struct Node {
    int data;
    int left;
    int right;
};

Node tree[MAX_NODES];
int nodeCount = 0;

int createNode(int value) {
    if (nodeCount >= MAX_NODES) {
        return -1;
    }

    tree[nodeCount].data = value;
    tree[nodeCount].left = -1;
    tree[nodeCount].right = -1;

    return nodeCount++;
}

int insertNode(int root, int value) {
    if (root == -1) {
        return createNode(value);
    }

    if (value < tree[root].data) {
        int child = insertNode(tree[root].left, value);
        if (child != -1) {
            tree[root].left = child;
        }
    } else if (value > tree[root].data) {
        int child = insertNode(tree[root].right, value);
        if (child != -1) {
            tree[root].right = child;
        }
    } else {
        cout << "Duplicate value ignored: " << value << '\n';
    }

    return root;
}

void preorderIterative(int root) {
    if (root == -1) {
        return;
    }

    int stack[MAX_NODES];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        int current = stack[top--];

        cout << tree[current].data << " ";

        // Push right first so left is processed first.
        if (tree[current].right != -1) {
            stack[++top] = tree[current].right;
        }

        if (tree[current].left != -1) {
            stack[++top] = tree[current].left;
        }
    }
}

void inorderIterative(int root) {
    int stack[MAX_NODES];
    int top = -1;
    int current = root;

    while (current != -1 || top >= 0) {
        while (current != -1) {
            stack[++top] = current;
            current = tree[current].left;
        }

        current = stack[top--];
        cout << tree[current].data << " ";

        current = tree[current].right;
    }
}

void postorderIterative(int root) {
    if (root == -1) {
        return;
    }

    int stack1[MAX_NODES];
    int stack2[MAX_NODES];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        int current = stack1[top1--];
        stack2[++top2] = current;

        if (tree[current].left != -1) {
            stack1[++top1] = tree[current].left;
        }

        if (tree[current].right != -1) {
            stack1[++top1] = tree[current].right;
        }
    }

    while (top2 >= 0) {
        cout << tree[stack2[top2--]].data << " ";
    }
}

int main() {
    int n;
    cout << "Enter number of nodes (1-" << MAX_NODES << "): ";
    cin >> n;

    if (n < 1 || n > MAX_NODES) {
        cout << "Invalid number of nodes.\n";
        return 1;
    }

    int root = -1;

    cout << "Enter " << n << " values:\n";

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "\nPreorder (iterative): ";
    preorderIterative(root);

    cout << "\nInorder (iterative): ";
    inorderIterative(root);

    cout << "\nPostorder (iterative): ";
    postorderIterative(root);

    cout << '\n';
    return 0;
}
