
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

const int MAX_VERTICES = 100;
const long long INF = LLONG_MAX / 4;

int main() {
    long long dist[MAX_VERTICES][MAX_VERTICES];
    int n;

    cout << "Enter number of vertices (1-"
         << MAX_VERTICES << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_VERTICES) {
        cerr << "Error: invalid number of vertices.\n";
        return 1;
    }

    cout << "Enter the adjacency matrix:\n";
    cout << "Use 0 for diagonal entries and -1 for no edge.\n";

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
                dist[i][j] = 0;
            } else if (weight == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = weight;
            }
        }
    }

    // Floyd-Warshall: try each vertex as an intermediate.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == INF) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (dist[k][j] == INF) {
                    continue;
                }

                long long candidate = dist[i][k] + dist[k][j];

                if (candidate < dist[i][j]) {
                    dist[i][j] = candidate;
                }
            }
        }
    }

    // A negative diagonal means a negative-weight cycle exists.
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cerr << "Error: graph contains a negative-weight cycle.\n";
            return 1;
        }
    }

    cout << "\nAll-Pairs Shortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << setw(8) << "INF";
            } else {
                cout << setw(8) << dist[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}
