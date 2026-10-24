
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX_ITEMS = 100;

struct Item {
    int id;
    double value;
    double weight;
    double ratio;
};

bool compareRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    Item items[MAX_ITEMS];
    int n;
    double capacity;

    cout << "Enter number of items (1-" << MAX_ITEMS << "): ";
    if (!(cin >> n) || n < 1 || n > MAX_ITEMS) {
        cerr << "Error: invalid number of items.\n";
        return 1;
    }

    cout << "Enter knapsack capacity: ";
    if (!(cin >> capacity) || capacity <= 0) {
        cerr << "Error: capacity must be positive.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";

        if (!(cin >> items[i].value >> items[i].weight)
            || items[i].value < 0
            || items[i].weight <= 0) {
            cerr << "Error: value must be non-negative "
                 << "and weight must be positive.\n";
            return 1;
        }

        items[i].id = i + 1;
        items[i].ratio = items[i].value / items[i].weight;
    }

    // Greedy choice: consider the highest value-to-weight ratio first.
    sort(items, items + n, compareRatio);

    double remainingCapacity = capacity;
    double totalValue = 0.0;

    cout << fixed << setprecision(2);
    cout << "\nSelected items:\n";
    cout << "Item\tFraction\tValue Added\tWeight Taken\n";

    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take the entire item.
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;

            cout << items[i].id << "\t"
                 << "100%\t\t"
                 << items[i].value << "\t\t"
                 << items[i].weight << '\n';
        } else {
            // Take only the fraction that fits.
            double fraction =
                remainingCapacity / items[i].weight;

            double valueAdded = fraction * items[i].value;
            double weightTaken = remainingCapacity;

            totalValue += valueAdded;
            remainingCapacity = 0;

            cout << items[i].id << "\t"
                 << fraction * 100 << "%\t\t"
                 << valueAdded << "\t\t"
                 << weightTaken << '\n';
        }
    }

    cout << "\nMaximum obtainable value: " << totalValue << '\n';
    cout << "Unused capacity: " << remainingCapacity << '\n';

    return 0;
}
