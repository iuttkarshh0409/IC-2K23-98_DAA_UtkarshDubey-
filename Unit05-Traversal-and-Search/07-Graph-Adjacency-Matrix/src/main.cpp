
#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

int main() {
    int vertices, edges;
    int matrix[MAX_VERTICES][MAX_VERTICES] = {};

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices < 1 || vertices > MAX_VERTICES ||
        edges < 0 || edges > vertices * (vertices - 1) / 2) {
        cout << "Invalid graph dimensions.\n";
        return 1;
    }

    cout << "Enter each edge (u v), using vertices 1 to "
         << vertices << ":\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 1 || u > vertices || v < 1 || v > vertices || u == v) {
            cout << "Invalid edge. Try again.\n";
            i--;
            continue;
        }

        // Undirected graph: both directions are connected.
        matrix[u - 1][v - 1] = 1;
        matrix[v - 1][u - 1] = 1;
    }

    cout << "\nAdjacency Matrix:\n    ";
    for (int i = 1; i <= vertices; i++) {
        cout << i << " ";
    }
    cout << '\n';

    for (int i = 0; i < vertices; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "\nAdjacent vertices:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i + 1 << ": ";
        bool found = false;

        for (int j = 0; j < vertices; j++) {
            if (matrix[i][j] == 1) {
                cout << j + 1 << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "None";
        }
        cout << '\n';
    }

    return 0;
}
