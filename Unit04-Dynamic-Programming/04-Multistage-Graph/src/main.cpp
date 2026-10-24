
#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;
const int INF = INT_MAX;

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {};
    int stage[MAX_VERTICES];
    int cost[MAX_VERTICES];
    int nextVertex[MAX_VERTICES];

    int n, m, stages;

    cout << "Enter number of vertices (2-"
         << MAX_VERTICES << "): ";

    if (!(cin >> n) || n < 2 || n > MAX_VERTICES) {
        cerr << "Error: invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter number of stages (2-" << n << "): ";

    if (!(cin >> stages) || stages < 2 || stages > n) {
        cerr << "Error: invalid number of stages.\n";
        return 1;
    }

    cout << "Enter number of directed edges (0-"
         << n * (n - 1) / 2 << "): ";

    if (!(cin >> m) || m < 0 || m > n * (n - 1) / 2) {
        cerr << "Error: invalid number of edges.\n";
        return 1;
    }

    cout << "\nEnter the stage number for each vertex (1 to "
         << stages << ").\n";

    for (int i = 0; i < n; i++) {
        cout << "Stage of vertex " << i + 1 << ": ";

        if (!(cin >> stage[i]) ||
            stage[i] < 1 || stage[i] > stages) {
            cerr << "Error: invalid stage number.\n";
            return 1;
        }
    }

    if (stage[0] != 1 || stage[n - 1] != stages) {
        cerr << "Error: vertex 1 must be in the first stage "
             << "and vertex " << n << " in the last stage.\n";
        return 1;
    }

    cout << "\nEnter each directed edge as: from to cost\n";

    for (int i = 0; i < m; i++) {
        int u, v, w;

        cout << "Edge " << i + 1 << ": ";

        if (!(cin >> u >> v >> w)) {
            cerr << "Error: invalid edge input.\n";
            return 1;
        }

        if (u < 1 || u > n || v < 1 || v > n ||
            stage[u - 1] >= stage[v - 1]) {
            cerr << "Error: edges must go from an earlier "
                 << "stage to a later stage.\n";
            return 1;
        }

        if (graph[u - 1][v - 1] != 0) {
            cerr << "Error: duplicate edge entered.\n";
            return 1;
        }

        graph[u - 1][v - 1] = w;
    }

    for (int i = 0; i < n; i++) {
        cost[i] = INF;
        nextVertex[i] = -1;
    }

    // Destination costs nothing more to reach.
    cost[n - 1] = 0;

    // Process vertices in reverse order.
    for (int u = n - 2; u >= 0; u--) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && cost[v] != INF) {
                long long candidate =
                    static_cast<long long>(graph[u][v]) + cost[v];

                if (candidate < cost[u]) {
                    cost[u] = static_cast<int>(candidate);
                    nextVertex[u] = v;
                }
            }
        }
    }

    if (cost[0] == INF) {
        cerr << "\nError: no path exists from vertex 1 "
             << "to vertex " << n << ".\n";
        return 1;
    }

    cout << "\nMinimum path cost: " << cost[0] << '\n';
    cout << "Minimum-cost path: ";

    int current = 0;
    cout << current + 1;

    while (current != n - 1) {
        current = nextVertex[current];

        if (current == -1) {
            cerr << "\nError: unable to reconstruct path.\n";
            return 1;
        }

        cout << " -> " << current + 1;
    }

    cout << '\n';

    return 0;
}
