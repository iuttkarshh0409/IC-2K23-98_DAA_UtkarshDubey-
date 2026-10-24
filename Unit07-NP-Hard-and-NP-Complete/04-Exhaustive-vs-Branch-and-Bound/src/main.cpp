
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int MAX_N = 20;

struct Item {
    int weight;
    int value;
};

Item items[MAX_N];
int n, capacity;

int exhaustiveBestValue;
int branchBestValue;

long long exhaustiveNodes;
long long branchNodes;

int currentSelection[MAX_N];
int bestSelection[MAX_N];

void exhaustiveSearch() {
    int totalSubsets = 1 << n;
    exhaustiveBestValue = 0;
    exhaustiveNodes = 0;

    for (int mask = 0; mask < totalSubsets; mask++) {
        exhaustiveNodes++;

        int totalWeight = 0;
        int totalValue = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                totalWeight += items[i].weight;
                totalValue += items[i].value;
            }
        }

        if (totalWeight <= capacity &&
            totalValue > exhaustiveBestValue) {
            exhaustiveBestValue = totalValue;
        }
    }
}

void branchAndBound(int index, int currentWeight, int currentValue) {
    branchNodes++;

    if (currentWeight > capacity) {
        return;
    }

    if (currentValue > branchBestValue) {
        branchBestValue = currentValue;

        for (int i = 0; i < n; i++) {
            bestSelection[i] = currentSelection[i];
        }
    }

    if (index == n) {
        return;
    }

    // Upper bound: assume all remaining values can be added.
    int upperBound = currentValue;

    for (int i = index; i < n; i++) {
        upperBound += items[i].value;
    }

    if (upperBound <= branchBestValue) {
        return;
    }

    // Include the current item.
    currentSelection[index] = 1;

    branchAndBound(
        index + 1,
        currentWeight + items[index].weight,
        currentValue + items[index].value
    );

    // Exclude the current item.
    currentSelection[index] = 0;

    branchAndBound(index + 1, currentWeight, currentValue);
}

void runBranchAndBound() {
    branchBestValue = 0;
    branchNodes = 0;

    for (int i = 0; i < n; i++) {
        currentSelection[i] = 0;
        bestSelection[i] = 0;
    }

    branchAndBound(0, 0, 0);
}

int main() {
    cout << "Enter number of items (1-20): ";
    cin >> n;

    if (n < 1 || n > MAX_N) {
        cout << "Invalid number of items.\n";
        return 1;
    }

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;

        if (items[i].weight <= 0 || items[i].value < 0) {
            cout << "Weights must be positive and values non-negative.\n";
            return 1;
        }
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Capacity must be non-negative.\n";
        return 1;
    }

    auto startExhaustive = high_resolution_clock::now();
    exhaustiveSearch();
    auto endExhaustive = high_resolution_clock::now();

    auto startBranch = high_resolution_clock::now();
    runBranchAndBound();
    auto endBranch = high_resolution_clock::now();

    double exhaustiveTime =
        duration<double, milli>(endExhaustive - startExhaustive).count();

    double branchTime =
        duration<double, milli>(endBranch - startBranch).count();

    cout << "\n--- Comparison Results ---\n";

    cout << "Exhaustive Search:\n";
    cout << "Maximum value: " << exhaustiveBestValue << "\n";
    cout << "Subsets checked: " << exhaustiveNodes << "\n";
    cout << "Execution time: " << exhaustiveTime << " ms\n";

    cout << "\nBranch and Bound:\n";
    cout << "Maximum value: " << branchBestValue << "\n";
    cout << "Search nodes visited: " << branchNodes << "\n";
    cout << "Execution time: " << branchTime << " ms\n";

    if (exhaustiveBestValue == branchBestValue) {
        cout << "\nBoth approaches found the same optimal value.\n";
    } else {
        cout << "\nWarning: results differ.\n";
    }

    return 0;
}
