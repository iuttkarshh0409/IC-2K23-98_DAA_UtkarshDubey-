
#include <iostream>
using namespace std;

const int MAX_LOCATIONS = 50;

int graph[MAX_LOCATIONS][MAX_LOCATIONS] = {};
bool locationAdded[MAX_LOCATIONS] = {};
int locationCount = 0;

void addLocation() {
    if (locationCount >= MAX_LOCATIONS) {
        cout << "Location limit reached.\n";
        return;
    }

    locationAdded[locationCount] = true;
    cout << "Location " << locationCount + 1
         << " added successfully.\n";
    locationCount++;
}

bool validLocation(int location) {
    return location >= 1 &&
           location <= locationCount &&
           locationAdded[location - 1];
}

void addConnection() {
    int u, v;

    if (locationCount < 2) {
        cout << "Add at least two locations first.\n";
        return;
    }

    cout << "Enter two location numbers: ";
    cin >> u >> v;

    if (!validLocation(u) || !validLocation(v) || u == v) {
        cout << "Invalid locations. Self-connections are not allowed.\n";
        return;
    }

    if (graph[u - 1][v - 1]) {
        cout << "Connection already exists.\n";
        return;
    }

    graph[u - 1][v - 1] = 1;
    graph[v - 1][u - 1] = 1;

    cout << "Connection added successfully.\n";
}

void displayNetwork() {
    if (locationCount == 0) {
        cout << "No locations available.\n";
        return;
    }

    cout << "\nNetwork Connections:\n";

    for (int i = 0; i < locationCount; i++) {
        cout << "Location " << i + 1 << ": ";
        bool found = false;

        for (int j = 0; j < locationCount; j++) {
            if (graph[i][j]) {
                cout << j + 1 << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "No connections";
        }
        cout << '\n';
    }
}

void exploreBFS(int start) {
    bool visited[MAX_LOCATIONS] = {};
    int queue[MAX_LOCATIONS];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS exploration: ";

    while (front < rear) {
        int current = queue[front++];
        cout << current + 1 << " ";

        for (int i = 0; i < locationCount; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    cout << '\n';
}

void exploreDFS(int start) {
    bool visited[MAX_LOCATIONS] = {};
    int stack[MAX_LOCATIONS];
    int top = -1;

    stack[++top] = start;
    visited[start] = true;

    cout << "DFS exploration: ";

    while (top >= 0) {
        int current = stack[top--];
        cout << current + 1 << " ";

        for (int i = locationCount - 1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                stack[++top] = i;
            }
        }
    }

    cout << '\n';
}

void shortestRoute(int start, int destination) {
    bool visited[MAX_LOCATIONS] = {};
    int parent[MAX_LOCATIONS];
    int queue[MAX_LOCATIONS];
    int front = 0, rear = 0;

    for (int i = 0; i < locationCount; i++) {
        parent[i] = -1;
    }

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        if (current == destination) {
            break;
        }

        for (int i = 0; i < locationCount; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = current;
                queue[rear++] = i;
            }
        }
    }

    if (!visited[destination]) {
        cout << "No route exists between these locations.\n";
        return;
    }

    int path[MAX_LOCATIONS];
    int length = 0;
    int current = destination;

    while (current != -1) {
        path[length++] = current;
        current = parent[current];
    }

    cout << "Shortest route: ";
    for (int i = length - 1; i >= 0; i--) {
        cout << path[i] + 1;
        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << "\nNumber of connections: " << length - 1 << '\n';
}

int main() {
    int choice;

    do {
        cout << "\n===== Network Exploration System =====\n";
        cout << "1. Add location\n";
        cout << "2. Add connection\n";
        cout << "3. Display network\n";
        cout << "4. Explore using BFS\n";
        cout << "5. Explore using DFS\n";
        cout << "6. Find shortest route\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            return 1;
        }

        int start, destination;

        switch (choice) {
            case 1:
                addLocation();
                break;

            case 2:
                addConnection();
                break;

            case 3:
                displayNetwork();
                break;

            case 4:
            case 5:
                if (locationCount == 0) {
                    cout << "Add locations first.\n";
                    break;
                }

                cout << "Enter starting location: ";
                cin >> start;

                if (!validLocation(start)) {
                    cout << "Invalid location.\n";
                    break;
                }

                if (choice == 4) {
                    exploreBFS(start - 1);
                } else {
                    exploreDFS(start - 1);
                }
                break;

            case 6:
                if (locationCount < 2) {
                    cout << "Add at least two locations first.\n";
                    break;
                }

                cout << "Enter source and destination: ";
                cin >> start >> destination;

                if (!validLocation(start) ||
                    !validLocation(destination)) {
                    cout << "Invalid locations.\n";
                    break;
                }

                shortestRoute(start - 1, destination - 1);
                break;

            case 0:
                cout << "Exiting Network Exploration System.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
