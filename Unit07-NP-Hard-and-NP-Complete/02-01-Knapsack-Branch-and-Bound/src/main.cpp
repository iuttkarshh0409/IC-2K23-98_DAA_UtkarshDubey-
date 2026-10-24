
#include <iostream>
using namespace std;

const int MAX_N = 20;

struct Item {
    int weight;
    int value;
    double ratio;
};

Item items[MAX_N];
int n, capacity;
int bestValue = 0;
int bestSelection[MAX_N] = {};
int currentSelection[MAX_N] = {};

void sortItems() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

double calculateBound(int index, int currentWeight, int currentValue) {
    if (currentWeight >= capacity) {
        return currentValue;
    }

    double bound = currentValue;
    int totalWeight = currentWeight;

    for (int i = index; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            bound += items[i].value;
        } else {
            int remaining = capacity - totalWeight;

            if (items[i].weight > 0) {
                bound += remaining * items[i].ratio;
            }
            break;
        }
    }

    return bound;
}

void knapsack(int index, int currentWeight, int currentValue) {
    if (currentWeight > capacity) {
        return;
    }

    if (currentValue > bestValue) {
        bestValue = currentValue;

        for (int i = 0; i < n; i++) {
            bestSelection[i] = currentSelection[i];
        }
    }

    if (index >= n) {
        return;
    }

    double bound = calculateBound(
        index, currentWeight, currentValue
    );

    if (bound <= bestValue) {
        return;
    }

    // Branch 1: Include the current item.
    currentSelection[index] = 1;

    knapsack(
        index + 1,
        currentWeight + items[index].weight,
        currentValue + items[index].value
    );

    // Branch 2: Exclude the current item.
    currentSelection[index] = 0;

    knapsack(index + 1, currentWeight, currentValue);
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

        items[i].ratio =
            static_cast<double>(items[i].value) / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Capacity must be non-negative.\n";
        return 1;
    }

    sortItems();

    knapsack(0, 0, 0);

    cout << "\nMaximum value: " << bestValue << "\n";
    cout << "Selected items (in sorted order):\n";

    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (bestSelection[i]) {
            cout << "Weight: " << items[i].weight
                 << ", Value: " << items[i].value << "\n";

            totalWeight += items[i].weight;
        }
    }

    cout << "Total weight: " << totalWeight << "\n";

    return 0;
}
