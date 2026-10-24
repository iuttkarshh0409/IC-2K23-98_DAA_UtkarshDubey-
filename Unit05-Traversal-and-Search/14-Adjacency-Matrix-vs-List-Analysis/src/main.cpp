
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int MAX_V = 100;
const int MAX_E = MAX_V * (MAX_V - 1) / 2;

int matrixGraph[MAX_V][MAX_V] = {};

int head[MAX_V];
int to[MAX_E * 2];
int nextEdge[MAX_E * 2];
int edgeCount = 0;

void initializeList(int vertices) {
    for (int i = 0; i < vertices; i++) {
        head[i] = -1;
    }
    edgeCount = 0;
}

void addDirectedEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}

int main() {
    int vertices, edges;
    int edgeU[MAX_E], edgeV[MAX_E];

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices < 1 || vertices > MAX_V ||
        edges < 0 || edges > vertices * (vertices - 1) / 2) {
        cout << "Invalid graph dimensions.\n";
        return 1;
    }

    cout << "Enter each undirected edge (u v):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 1 || u > vertices || v < 1 ||
            v > vertices || u == v) {
            cout << "Invalid edge. Try again.\n";
            i--;
            continue;
        }

        edgeU[i] = u - 1;
        edgeV[i] = v - 1;
    }

    // Build adjacency matrix and measure construction time.
    auto matrixStart = high_resolution_clock::now();

    for (int i = 0; i < edges; i++) {
        int u = edgeU[i], v = edgeV[i];
        matrixGraph[u][v] = 1;
        matrixGraph[v][u] = 1;
    }

    auto matrixEnd = high_resolution_clock::now();

    // Build adjacency list and measure construction time.
    initializeList(vertices);

    auto listStart = high_resolution_clock::now();

    for (int i = 0; i < edges; i++) {
        int u = edgeU[i], v = edgeV[i];
        addDirectedEdge(u, v);
        addDirectedEdge(v, u);
    }

    auto listEnd = high_resolution_clock::now();

    // Count neighbors of every vertex using the matrix.
    int matrixNeighborCount = 0;

    auto matrixScanStart = high_resolution_clock::now();

    for (int u = 0; u < vertices; u++) {
        for (int v = 0; v < vertices; v++) {
            if (matrixGraph[u][v]) {
                matrixNeighborCount++;
            }
        }
    }

    auto matrixScanEnd = high_resolution_clock::now();

    // Count neighbors of every vertex using the adjacency list.
    int listNeighborCount = 0;

    auto listScanStart = high_resolution_clock::now();

    for (int u = 0; u < vertices; u++) {
        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            listNeighborCount++;
        }
    }

    auto listScanEnd = high_resolution_clock::now();

    double matrixBuildTime =
        duration<double, micro>(matrixEnd - matrixStart).count();

    double listBuildTime =
        duration<double, micro>(listEnd - listStart).count();

    double matrixScanTime =
        duration<double, micro>(
            matrixScanEnd - matrixScanStart).count();

    double listScanTime =
        duration<double, micro>(
            listScanEnd - listScanStart).count();

    cout << "\n--- Graph Representation Comparison ---\n";
    cout << "Vertices: " << vertices << '\n';
    cout << "Input edges: " << edges << '\n';

    cout << "\nAdjacency Matrix:\n";
    cout << "Directed adjacency entries: "
         << matrixNeighborCount << '\n';
    cout << "Construction time: "
         << matrixBuildTime << " microseconds\n";
    cout << "Full neighbor scan time: "
         << matrixScanTime << " microseconds\n";
    cout << "Allocated storage: "
         << sizeof(matrixGraph) << " bytes\n";

    cout << "\nAdjacency List:\n";
    cout << "Directed adjacency entries: "
         << listNeighborCount << '\n';
    cout << "Construction time: "
         << listBuildTime << " microseconds\n";
    cout << "Full neighbor scan time: "
         << listScanTime << " microseconds\n";
    cout << "Allocated storage for active graph arrays: "
         << sizeof(head) + sizeof(to) + sizeof(nextEdge)
         << " bytes\n";

    cout << "\nTheoretical Comparison:\n";
    cout << "Matrix storage: O(V^2)\n";
    cout << "List storage: O(V + E)\n";
    cout << "Matrix full neighbor scan: O(V^2)\n";
    cout << "List full neighbor scan: O(V + E)\n";

    if (matrixNeighborCount == listNeighborCount) {
        cout << "\nValidation: Both representations store "
             << "the same number of adjacency entries.\n";
    } else {
        cout << "\nValidation failed: adjacency counts differ.\n";
    }

    return 0;
}
