
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;
const int INF = INT_MAX;

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    bool selected[MAX_VERTICES] = {};
    int n;

    cout << "Enter number of vertices (1-" 
         << MAX_VERTICES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_VERTICES) {
        cerr << "Error: invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter the adjacency matrix\n";
    cout << "(Use 0 for no edge and positive weights for edges):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(cin >> graph[i][j])) {
                cerr << "Error: invalid matrix input.\n";
                return 1;
            }

            if (graph[i][j] < 0) {
                cerr << "Error: negative weights are not supported.\n";
                return 1;
            }
        }
    }

    // Validate an undirected graph with no self-loops.
    for (int i = 0; i < n; i++) {
        if (graph[i][i] != 0) {
            cerr << "Error: diagonal entries must be zero.\n";
            return 1;
        }

        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != graph[j][i]) {
                cerr << "Error: the matrix must be symmetric.\n";
                return 1;
            }
        }
    }

    // A single vertex already forms a spanning tree.
    if (n == 1) {
        cout << "\nMinimum Spanning Tree:\n";
        cout << "No edges required.\n";
        cout << "Minimum total cost: 0\n";
        return 0;
    }

    selected[0] = true;
    int edgesAdded = 0;
    long long totalCost = 0;

    cout << "\nMinimum Spanning Tree edges:\n";
    cout << "Edge\tWeight\n";

    while (edgesAdded < n - 1) {
        int minimum = INF;
        int from = -1;
        int to = -1;

        // Find the cheapest edge crossing the selected boundary.
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

        // No connecting edge means the graph is disconnected.
        if (to == -1) {
            cerr << "\nError: graph is disconnected; "
                 << "a spanning tree does not exist.\n";
            return 1;
        }

        selected[to] = true;
        totalCost += minimum;
        edgesAdded++;

        cout << from + 1 << " - " << to + 1
             << "\t" << minimum << '\n';
    }

    cout << "\nMinimum total cost: " << totalCost << '\n';

    return 0;
}
