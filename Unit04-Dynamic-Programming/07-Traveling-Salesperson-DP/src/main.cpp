
#include <iostream>
#include <climits>
using namespace std;

const int MAX_CITIES = 15;
const long long INF = LLONG_MAX / 4;

long long cost[MAX_CITIES][MAX_CITIES];
long long dp[1 << MAX_CITIES][MAX_CITIES];
int parent[1 << MAX_CITIES][MAX_CITIES];

int main() {
    int n;

    cout << "Enter number of cities (1-" << MAX_CITIES << "): ";
    if (!(cin >> n) || n < 1 || n > MAX_CITIES) {
        cerr << "Error: invalid number of cities.\n";
        return 1;
    }

    cout << "Enter the cost matrix (-1 for no route, 0 on diagonal):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long value;

            if (!(cin >> value)) {
                cerr << "Error: invalid matrix input.\n";
                return 1;
            }

            if (i == j) {
                if (value != 0) {
                    cerr << "Error: diagonal entries must be zero.\n";
                    return 1;
                }
                cost[i][j] = 0;
            } else {
                if (value < -1) {
                    cerr << "Error: negative costs are not supported.\n";
                    return 1;
                }
                cost[i][j] = (value == -1) ? INF : value;
            }
        }
    }

    const int totalMasks = 1 << n;

    for (int mask = 0; mask < totalMasks; mask++) {
        for (int city = 0; city < n; city++) {
            dp[mask][city] = INF;
            parent[mask][city] = -1;
        }
    }

    // Start at city 1, represented by index 0.
    dp[1][0] = 0;

    for (int mask = 1; mask < totalMasks; mask++) {
        if ((mask & 1) == 0) {
            continue;
        }

        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0 || dp[mask][u] == INF) {
                continue;
            }

            for (int v = 0; v < n; v++) {
                if ((mask & (1 << v)) != 0 || cost[u][v] == INF) {
                    continue;
                }

                int nextMask = mask | (1 << v);
                long long candidate = dp[mask][u] + cost[u][v];

                if (candidate < dp[nextMask][v]) {
                    dp[nextMask][v] = candidate;
                    parent[nextMask][v] = u;
                }
            }
        }
    }

    int fullMask = totalMasks - 1;
    long long minimumCost = INF;
    int lastCity = -1;

    // Return from the final city to the starting city.
    for (int city = 1; city < n; city++) {
        if (dp[fullMask][city] == INF || cost[city][0] == INF) {
            continue;
        }

        long long totalCost = dp[fullMask][city] + cost[city][0];

        if (totalCost < minimumCost) {
            minimumCost = totalCost;
            lastCity = city;
        }
    }

    // Special case: a tour containing only one city.
    if (n == 1) {
        cout << "\nMinimum tour cost: 0\n";
        cout << "Tour: 1 -> 1\n";
        return 0;
    }

    if (lastCity == -1) {
        cout << "\nNo complete tour exists.\n";
        return 0;
    }

    int tour[MAX_CITIES + 1];
    int tourLength = 0;
    int mask = fullMask;
    int current = lastCity;

    while (current != -1 && tourLength < n) {
        tour[tourLength++] = current;
        int previous = parent[mask][current];
        mask ^= (1 << current);
        current = previous;
    }

    cout << "\nMinimum tour cost: " << minimumCost << '\n';
    cout << "Tour: ";

    for (int i = tourLength - 1; i >= 0; i--) {
        cout << tour[i] + 1 << " -> ";
    }

    cout << "1\n";
    return 0;
}
