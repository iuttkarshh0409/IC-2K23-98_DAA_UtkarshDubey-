
#include <iostream>
#include <climits>
using namespace std;

const int MAX_N = 10;
const int INF = INT_MAX / 4;

int cost[MAX_N][MAX_N];
bool visited[MAX_N];
int path[MAX_N];
int bestPath[MAX_N];
int n;
int bestCost = INF;

void tsp(int currentCity, int level, int currentCost) {
    if (level == n) {
        if (cost[currentCity][0] != 0) {
            int totalCost = currentCost + cost[currentCity][0];

            if (totalCost < bestCost) {
                bestCost = totalCost;

                for (int i = 0; i < n; i++) {
                    bestPath[i] = path[i];
                }
            }
        }
        return;
    }

    if (currentCost >= bestCost) {
        return;
    }

    for (int nextCity = 1; nextCity < n; nextCity++) {
        if (!visited[nextCity] && cost[currentCity][nextCity] != 0) {
            int nextCost = currentCost + cost[currentCity][nextCity];

            if (nextCost >= bestCost) {
                continue;
            }

            visited[nextCity] = true;
            path[level] = nextCity;

            tsp(nextCity, level + 1, nextCost);

            visited[nextCity] = false;
        }
    }
}

int main() {
    cout << "Enter number of cities (2-10): ";
    cin >> n;

    if (n < 2 || n > MAX_N) {
        cout << "Invalid number of cities.\n";
        return 1;
    }

    cout << "Enter the cost matrix (0 means no direct route):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (cost[i][j] < 0) {
                cout << "Costs must be non-negative.\n";
                return 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    path[0] = 0;

    tsp(0, 1, 0);

    if (bestCost == INF) {
        cout << "\nNo complete tour exists.\n";
    } else {
        cout << "\nMinimum tour cost: " << bestCost << "\n";
        cout << "Optimal tour: ";

        for (int i = 0; i < n; i++) {
            cout << bestPath[i] << " -> ";
        }

        cout << "0\n";
    }

    return 0;
}
