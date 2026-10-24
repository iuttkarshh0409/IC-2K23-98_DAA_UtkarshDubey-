
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

        if (child != -1 || tree[root].left == -1) {
            tree[root].left = child;
        }
    } else if (value > tree[root].data) {
        int child = insertNode(tree[root].right, value);

        if (child != -1 || tree[root].right == -1) {
            tree[root].right = child;
        }
    } else {
        cout << "Duplicate values are not allowed: "
             << value << '\n';
    }

    return root;
}

void displayInorder(int root) {
    if (root == -1) {
        return;
    }

    displayInorder(tree[root].left);
    cout << tree[root].data << ' ';
    displayInorder(tree[root].right);
}

int main() {
    int n;
    int root = -1;

    cout << "Enter number of nodes (1-" << MAX_NODES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_NODES) {
        cerr << "Error: invalid number of nodes.\n";
        return 1;
    }

    cout << "Enter " << n << " distinct integer values:\n";

    for (int i = 0; i < n; i++) {
        int value;

        if (!(cin >> value)) {
            cerr << "Error: invalid node value.\n";
            return 1;
        }

        int previousCount = nodeCount;
        int newRoot = insertNode(root, value);

        if (root == -1) {
            root = newRoot;
        }

        if (nodeCount == previousCount &&
            previousCount < MAX_NODES &&
            value != tree[root].data) {
            // A duplicate or failed insertion did not add a node.
        }
    }

    cout << "\nBinary Search Tree created successfully.\n";
    cout << "Number of nodes: " << nodeCount << '\n';
    cout << "Inorder traversal: ";
    displayInorder(root);
    cout << '\n';

    return 0;
}
