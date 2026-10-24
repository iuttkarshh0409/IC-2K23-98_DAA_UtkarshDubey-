
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_ITEMS = 100;
const int MAX_CAPACITY = 1000;

int main() {
    int n, capacity;
    int values[MAX_ITEMS];
    int weights[MAX_ITEMS];
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1] = {};

    cout << "Enter number of items (1-" << MAX_ITEMS << "): ";

    if (!(cin >> n) || n < 1 || n > MAX_ITEMS) {
        cerr << "Error: invalid number of items.\n";
        return 1;
    }

    cout << "Enter knapsack capacity (0-"
         << MAX_CAPACITY << "): ";

    if (!(cin >> capacity) ||
        capacity < 0 || capacity > MAX_CAPACITY) {
        cerr << "Error: invalid knapsack capacity.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item "
             << i + 1 << ": ";

        if (!(cin >> values[i] >> weights[i]) ||
            values[i] < 0 || weights[i] <= 0) {
            cerr << "Error: values must be non-negative "
                 << "and weights must be positive.\n";
            return 1;
        }
    }

    // Build the DP table.
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            // Option 1: do not take the current item.
            dp[i][w] = dp[i - 1][w];

            // Option 2: take the item if it fits.
            if (weights[i - 1] <= w) {
                int includedValue =
                    values[i - 1] +
                    dp[i - 1][w - weights[i - 1]];

                if (includedValue > dp[i][w]) {
                    dp[i][w] = includedValue;
                }
            }
        }
    }

    cout << "\nMaximum obtainable value: "
         << dp[n][capacity] << '\n';

    // Trace the table backwards to identify selected items.
    int remainingCapacity = capacity;
    bool selected[MAX_ITEMS] = {};

    for (int i = n; i > 0; i--) {
        if (dp[i][remainingCapacity] !=
            dp[i - 1][remainingCapacity]) {
            selected[i - 1] = true;
            remainingCapacity -= weights[i - 1];
        }
    }

    cout << "\nSelected items:\n";
    cout << "Item\tValue\tWeight\n";

    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            cout << i + 1 << '\t'
                 << values[i] << '\t'
                 << weights[i] << '\n';

            totalWeight += weights[i];
        }
    }

    cout << "\nTotal selected weight: "
         << totalWeight << '\n';

    cout << "Unused capacity: "
         << capacity - totalWeight << '\n';

    return 0;
}
