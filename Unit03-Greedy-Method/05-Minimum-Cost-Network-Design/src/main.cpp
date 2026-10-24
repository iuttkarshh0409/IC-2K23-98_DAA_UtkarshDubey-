
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = MAX_VERTICES * (MAX_VERTICES - 1) / 2;
const int INF = INT_MAX;

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

int runPrim(int graph[][MAX_VERTICES], int n,
            Edge result[], int &count, long long &cost) {
    bool selected[MAX_VERTICES] = {};
    selected[0] = true;
    count = 0;
    cost = 0;

    while (count < n - 1) {
        int minimum = INF;
        int from = -1;
        int to = -1;

        for (int i = 0; i < n; i++) {
            if (!selected[i]) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (!selected[j] &&
                    graph[i][j] > 0 &&
                    graph[i][j] < minimum) {
                    minimum = graph[i][j];
                    from = i;
                    to = j;
                }
            }
        }

        if (to == -1) {
            return 0;
        }

        selected[to] = true;
        result[count++] = {from, to, minimum};
        cost += minimum;
    }

    return 1;
}

int runKruskal(Edge edges[], int m, int n,
               Edge result[], int &count, long long &cost) {
    sort(edges, edges + m, compareWeight);

    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES] = {};

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    count = 0;
    cost = 0;

    for (int i = 0; i < m && count < n - 1; i++) {
        if (uniteSets(parent, rank, edges[i].from, edges[i].to)) {
            result[count++] = edges[i];
            cost += edges[i].weight;
        }
    }

    return count == n - 1;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {};
    Edge edges[MAX_EDGES];
    Edge primEdges[MAX_VERTICES];
    Edge kruskalEdges[MAX_VERTICES];

    int n, m = 0;

    cout << "=== Minimum-Cost Network Design System ===\n";
    cout << "Enter number of locations (1-"
         << MAX_VERTICES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_VERTICES) {
        cerr << "Error: invalid number of locations.\n";
        return 1;
    }

    if (n == 1) {
        cout << "\nA single location requires no connections.\n";
        cout << "Minimum network cost: 0\n";
        return 0;
    }

    cout << "Enter the number of possible connections (0-"
         << n * (n - 1) / 2 << "): ";

    if (!(cin >> m) || m < 0 || m > n * (n - 1) / 2) {
        cerr << "Error: invalid number of connections.\n";
        return 1;
    }

    cout << "\nEnter each connection as: location1 location2 cost\n";
    cout << "Use location numbers from 1 to " << n << ".\n";

    for (int i = 0; i < m; i++) {
        int u, v, w;

        cout << "Connection " << i + 1 << ": ";

        if (!(cin >> u >> v >> w)) {
            cerr << "Error: invalid connection input.\n";
            return 1;
        }

        if (u < 1 || u > n || v < 1 || v > n || u == v) {
            cerr << "Error: invalid location numbers.\n";
            return 1;
        }

        if (w <= 0) {
            cerr << "Error: connection cost must be positive.\n";
            return 1;
        }

        if (graph[u - 1][v - 1] != 0) {
            cerr << "Error: duplicate connection entered.\n";
            return 1;
        }

        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;

        edges[i] = {u - 1, v - 1, w};
    }

    int primCount, kruskalCount;
    long long primCost, kruskalCost;

    if (!runPrim(graph, n, primEdges, primCount, primCost)) {
        cerr << "\nError: network is disconnected.\n";
        cerr << "Every location cannot be connected.\n";
        return 1;
    }

    if (!runKruskal(edges, m, n, kruskalEdges,
                    kruskalCount, kruskalCost)) {
        cerr << "\nError: network is disconnected.\n";
        return 1;
    }

    cout << "\n=== Prim's Algorithm ===\n";
    cout << "Connection\tCost\n";

    for (int i = 0; i < primCount; i++) {
        cout << primEdges[i].from + 1 << " - "
             << primEdges[i].to + 1 << "\t\t"
             << primEdges[i].weight << '\n';
    }

    cout << "Total network cost: " << primCost << '\n';

    cout << "\n=== Kruskal's Algorithm ===\n";
    cout << "Connection\tCost\n";

    for (int i = 0; i < kruskalCount; i++) {
        cout << kruskalEdges[i].from + 1 << " - "
             << kruskalEdges[i].to + 1 << "\t\t"
             << kruskalEdges[i].weight << '\n';
    }

    cout << "Total network cost: " << kruskalCost << '\n';

    cout << "\n=== Comparison ===\n";

    if (primCost == kruskalCost) {
        cout << "Both algorithms produced the same minimum cost: "
             << primCost << '\n';
    } else {
        cout << "Warning: the calculated costs differ.\n";
    }

    return 0;
}
