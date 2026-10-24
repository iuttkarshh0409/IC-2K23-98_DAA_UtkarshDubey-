
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

const int MAX_LOCATIONS = 20;
const long long INF = LLONG_MAX / 4;

struct Route {
    int from;
    int to;
    long long cost;
};

long long graph[MAX_LOCATIONS][MAX_LOCATIONS];

void initializeGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void addRoute(int n) {
    int from, to;
    long long cost;

    cout << "Enter source location (1-" << n << "): ";
    if (!(cin >> from) || from < 1 || from > n) {
        cerr << "Invalid source location.\n";
        return;
    }

    cout << "Enter destination location (1-" << n << "): ";
    if (!(cin >> to) || to < 1 || to > n || to == from) {
        cerr << "Invalid destination location.\n";
        return;
    }

    cout << "Enter route cost (non-negative): ";
    if (!(cin >> cost) || cost < 0) {
        cerr << "Invalid route cost.\n";
        return;
    }

    // Store the route in both directions.
    graph[from - 1][to - 1] = cost;
    graph[to - 1][from - 1] = cost;

    cout << "Route added successfully.\n";
}

void displayRoutes(int n) {
    cout << "\nRoute Cost Matrix (- means no direct route):\n";
    cout << setw(8) << "";

    for (int i = 0; i < n; i++) {
        cout << setw(8) << i + 1;
    }
    cout << '\n';

    for (int i = 0; i < n; i++) {
        cout << setw(8) << i + 1;

        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                cout << setw(8) << "-";
            } else {
                cout << setw(8) << graph[i][j];
            }
        }
        cout << '\n';
    }
}

void findBestRoute(int n) {
    int source, destination;

    cout << "Enter starting location (1-" << n << "): ";
    if (!(cin >> source) || source < 1 || source > n) {
        cerr << "Invalid starting location.\n";
        return;
    }

    cout << "Enter destination location (1-" << n << "): ";
    if (!(cin >> destination) || destination < 1 ||
        destination > n) {
        cerr << "Invalid destination location.\n";
        return;
    }

    long long distance[MAX_LOCATIONS];
    bool visited[MAX_LOCATIONS] = {};
    int parent[MAX_LOCATIONS];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }

    distance[source - 1] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        long long minimum = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minimum) {
                minimum = distance[i];
                u = i;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                long long candidate = distance[u] + graph[u][v];

                if (candidate < distance[v]) {
                    distance[v] = candidate;
                    parent[v] = u;
                }
            }
        }
    }

    if (distance[destination - 1] == INF) {
        cout << "\nNo route exists between locations "
             << source << " and " << destination << ".\n";
        return;
    }

    int path[MAX_LOCATIONS];
    int pathLength = 0;
    int current = destination - 1;

    while (current != -1 && pathLength < n) {
        path[pathLength++] = current;
        current = parent[current];
    }

    cout << "\n========== ROUTE REPORT ==========\n";
    cout << "Starting location: " << source << '\n';
    cout << "Destination: " << destination << '\n';
    cout << "Minimum route cost: "
         << distance[destination - 1] << '\n';
    cout << "Optimal route: ";

    for (int i = pathLength - 1; i >= 0; i--) {
        cout << path[i] + 1;
        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << "\n==================================\n";
}

int main() {
    int n;

    cout << "=== ROUTE OPTIMIZATION SYSTEM ===\n";
    cout << "Enter number of locations (1-"
         << MAX_LOCATIONS << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_LOCATIONS) {
        cerr << "Invalid number of locations.\n";
        return 1;
    }

    initializeGraph(n);

    int choice;

    do {
        cout << "\n1. Add or update a route\n";
        cout << "2. Display route matrix\n";
        cout << "3. Find minimum-cost route\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cerr << "Invalid menu input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                addRoute(n);
                break;
            case 2:
                displayRoutes(n);
                break;
            case 3:
                findBestRoute(n);
                break;
            case 4:
                cout << "Exiting Route Optimization System.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
