
#include <iostream>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;
const long long INF = LLONG_MAX / 4;

int main() {
    long long graph[MAX_VERTICES][MAX_VERTICES];
    long long distance[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {};
    int parent[MAX_VERTICES];
    int n, source;

    cout << "Enter number of vertices (1-"
         << MAX_VERTICES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_VERTICES) {
        cerr << "Error: invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter the adjacency matrix:\n";
    cout << "Use -1 for no edge and 0 on the diagonal.\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long weight;

            if (!(cin >> weight)) {
                cerr << "Error: invalid matrix input.\n";
                return 1;
            }

            if (i == j) {
                if (weight != 0) {
                    cerr << "Error: diagonal entries must be zero.\n";
                    return 1;
                }
                graph[i][j] = 0;
            } else {
                if (weight < -1) {
                    cerr << "Error: negative edge weights "
                         << "are not supported.\n";
                    return 1;
                }

                graph[i][j] = (weight == -1) ? INF : weight;
            }
        }
    }

    cout << "Enter source vertex (1-" << n << "): ";

    if (!(cin >> source) || source < 1 || source > n) {
        cerr << "Error: invalid source vertex.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }

    distance[source - 1] = 0;

    // Dijkstra's algorithm using an adjacency matrix.
    for (int count = 0; count < n; count++) {
        int u = -1;
        long long minimum = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minimum) {
                minimum = distance[i];
                u = i;
            }
        }

        // No remaining reachable vertex.
        if (u == -1) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                long long candidate =
                    distance[u] + graph[u][v];

                if (candidate < distance[v]) {
                    distance[v] = candidate;
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\nShortest distances from vertex "
         << source << ":\n";

    cout << "Vertex\tDistance\tPath\n";

    for (int v = 0; v < n; v++) {
        cout << v + 1 << '\t';

        if (distance[v] == INF) {
            cout << "INF\t\tNo path\n";
            continue;
        }

        cout << distance[v] << "\t\t";

        int path[MAX_VERTICES];
        int pathLength = 0;
        int current = v;

        while (current != -1 && pathLength < MAX_VERTICES) {
            path[pathLength++] = current;
            current = parent[current];
        }

        for (int i = pathLength - 1; i >= 0; i--) {
            cout << path[i] + 1;

            if (i > 0) {
                cout << " -> ";
            }
        }

        cout << '\n';
    }

    return 0;
}
