
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
        cout << "Duplicate value ignored: " << value << '\n';
    }

    return root;
}

void inorder(int root) {
    if (root == -1) {
        return;
    }

    inorder(tree[root].left);
    cout << tree[root].data << ' ';
    inorder(tree[root].right);
}

int main() {
    int n;
    int root = -1;

    cout << "Enter number of nodes (1-" << MAX_NODES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_NODES) {
        cerr << "Error: invalid number of nodes.\n";
        return 1;
    }

    cout << "Enter " << n << " integer values:\n";

    for (int i = 0; i < n; i++) {
        int value;

        if (!(cin >> value)) {
            cerr << "Error: invalid node value.\n";
            return 1;
        }

        if (nodeCount >= MAX_NODES) {
            cerr << "Error: tree capacity exceeded.\n";
            return 1;
        }

        root = insertNode(root, value);
    }

    cout << "\nInorder traversal (Left, Root, Right): ";
    inorder(root);
    cout << '\n';

    return 0;
}
