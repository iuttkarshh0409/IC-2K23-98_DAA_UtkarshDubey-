
#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

int graph[MAX_VERTICES][MAX_VERTICES] = {};
bool visited[MAX_VERTICES] = {};
int vertices;

void iterativeDFS(int start) {
    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = start;

    cout << "Iterative DFS Traversal: ";

    while (top >= 0) {
        int current = stack[top--];

        if (visited[current]) {
            continue;
        }

        visited[current] = true;
        cout << current + 1 << " ";

        // Push neighbors in reverse order so that
        // smaller-numbered vertices are processed first.
        for (int i = vertices - 1; i >= 0; i--) {
            if (graph[current][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }

    cout << '\n';
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

    iterativeDFS(start - 1);

    bool disconnected = false;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            disconnected = true;
            break;
        }
    }

    if (disconnected) {
        cout << "Note: Some vertices are unreachable from the "
             << "starting vertex.\n";
    }

    return 0;
}
