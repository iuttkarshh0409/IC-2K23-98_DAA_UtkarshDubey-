
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = MAX_VERTICES * (MAX_VERTICES - 1) / 2;

struct Edge {
    int from;
    int to;
    int weight;
};

bool compareWeight(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int parent[], int vertex) {
    while (parent[vertex] != vertex) {
        parent[vertex] = parent[parent[vertex]];
        vertex = parent[vertex];
    }

    return vertex;
}

bool uniteSets(int parent[], int rank[], int a, int b) {
    int rootA = findParent(parent, a);
    int rootB = findParent(parent, b);

    if (rootA == rootB) {
        return false;
    }

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    } else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }

    return true;
}

int main() {
    Edge edges[MAX_EDGES];
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES] = {};
    int n, m;

    cout << "Enter number of vertices (1-"
         << MAX_VERTICES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_VERTICES) {
        cerr << "Error: invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter number of edges (0-"
         << MAX_EDGES << "): ";

    if (!(cin >> m) || m < 0 || m > MAX_EDGES) {
        cerr << "Error: invalid number of edges.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;

        cout << "Enter edge " << i + 1
             << " (from to weight): ";

        if (!(cin >> u >> v >> w)) {
            cerr << "Error: invalid edge input.\n";
            return 1;
        }

        if (u < 1 || u > n || v < 1 || v > n) {
            cerr << "Error: vertex numbers must be between 1 and n.\n";
            return 1;
        }

        if (u == v) {
            cerr << "Error: self-loops are not supported.\n";
            return 1;
        }

        if (w < 0) {
            cerr << "Error: negative weights are not supported.\n";
            return 1;
        }

        edges[i] = {u - 1, v - 1, w};
    }

    sort(edges, edges + m, compareWeight);

    long long totalCost = 0;
    int edgesAdded = 0;

    cout << "\nMinimum Spanning Tree edges:\n";
    cout << "Edge\tWeight\n";

    for (int i = 0; i < m && edgesAdded < n - 1; i++) {
        if (uniteSets(parent, rank, edges[i].from, edges[i].to)) {
            cout << edges[i].from + 1 << " - "
                 << edges[i].to + 1 << "\t"
                 << edges[i].weight << '\n';

            totalCost += edges[i].weight;
            edgesAdded++;
        }
    }

    if (edgesAdded != n - 1) {
        cerr << "\nError: graph is disconnected; "
             << "a spanning tree does not exist.\n";
        return 1;
    }

    cout << "\nMinimum total cost: " << totalCost << '\n';

    return 0;
}
