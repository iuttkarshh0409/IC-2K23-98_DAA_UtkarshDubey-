
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int MAX_VERTICES = 100;

int graph[MAX_VERTICES][MAX_VERTICES] = {};
int vertices;

void runBFS(int start, int order[], int &count) {
    bool visited[MAX_VERTICES] = {};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    count = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        order[count++] = current;

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void runDFS(int start, int order[], int &count) {
    bool visited[MAX_VERTICES] = {};
    int stack[MAX_VERTICES];
    int top = -1;
    count = 0;

    stack[++top] = start;
    visited[start] = true;

    while (top >= 0) {
        int current = stack[top--];
        order[count++] = current;

        for (int i = vertices - 1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                stack[++top] = i;
            }
        }
    }
}

int main() {
    int edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices < 1 || vertices > MAX_VERTICES ||
        edges < 0 || edges > vertices * (vertices - 1) / 2) {
        cout << "Invalid graph dimensions.\n";
        return 1;
    }

    cout << "Enter each undirected edge (u v):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 1 || u > vertices || v < 1 || v > vertices ||
            u == v) {
            cout << "Invalid edge. Try again.\n";
            i--;
            continue;
        }

        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 1 || start > vertices) {
        cout << "Invalid starting vertex.\n";
        return 1;
    }
    start--;

    int bfsOrder[MAX_VERTICES], dfsOrder[MAX_VERTICES];
    int bfsCount, dfsCount;

    auto bfsStart = high_resolution_clock::now();
    runBFS(start, bfsOrder, bfsCount);
    auto bfsEnd = high_resolution_clock::now();

    auto dfsStart = high_resolution_clock::now();
    runDFS(start, dfsOrder, dfsCount);
    auto dfsEnd = high_resolution_clock::now();

    double bfsTime = duration<double, micro>(
        bfsEnd - bfsStart).count();

    double dfsTime = duration<double, micro>(
        dfsEnd - dfsStart).count();

    cout << "\nBFS order: ";
    for (int i = 0; i < bfsCount; i++) {
        cout << bfsOrder[i] + 1 << " ";
    }

    cout << "\nDFS order: ";
    for (int i = 0; i < dfsCount; i++) {
        cout << dfsOrder[i] + 1 << " ";
    }

    cout << "\n\nVertices reached by BFS: " << bfsCount;
    cout << "\nVertices reached by DFS: " << dfsCount;

    cout << "\n\nBFS execution time: " << bfsTime << " microseconds";
    cout << "\nDFS execution time: " << dfsTime << " microseconds\n";

    cout << "\nAnalysis:\n";
    cout << "Both traversals should reach the same vertices "
         << "from the same starting vertex.\n";
    cout << "With an adjacency matrix, both have O(V^2) "
         << "worst-case traversal time.\n";
    cout << "Measured times can vary with graph size and system load.\n";

    return 0;
}
