
#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = MAX_VERTICES * (MAX_VERTICES - 1);

int head[MAX_VERTICES];
int to[MAX_EDGES];
int nextEdge[MAX_EDGES];
int edgeCount = 0;

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        head[i] = -1;
    }
}

bool addDirectedEdge(int u, int v) {
    if (edgeCount >= MAX_EDGES) {
        return false;
    }

    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount;
    edgeCount++;

    return true;
}

bool hasEdge(int u, int v) {
    for (int edge = head[u]; edge != -1; edge = nextEdge[edge]) {
        if (to[edge] == v) {
            return true;
        }
    }
    return false;
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices < 1 || vertices > MAX_VERTICES ||
        edges < 0 || edges > vertices * (vertices - 1) / 2) {
        cout << "Invalid graph dimensions.\n";
        return 1;
    }

    initializeGraph(vertices);

    cout << "Enter each edge (u v), using vertices 1 to "
         << vertices << ":\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 1 || u > vertices || v < 1 || v > vertices ||
            u == v) {
            cout << "Invalid edge. Try again.\n";
            i--;
            continue;
        }

        u--;
        v--;

        // Avoid duplicate edges in this simple undirected graph.
        if (hasEdge(u, v)) {
            cout << "Duplicate edge ignored: "
                 << u + 1 << " " << v + 1 << '\n';
            continue;
        }

        if (!addDirectedEdge(u, v) || !addDirectedEdge(v, u)) {
            cout << "Edge storage capacity exceeded.\n";
            return 1;
        }
    }

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < vertices; i++) {
        cout << i + 1 << " -> ";

        int edge = head[i];
        if (edge == -1) {
            cout << "None";
        }

        while (edge != -1) {
            cout << to[edge] + 1;
            edge = nextEdge[edge];

            if (edge != -1) {
                cout << " -> ";
            }
        }

        cout << '\n';
    }

    return 0;
}
