
#include <iostream>
using namespace std;

const int MAX_N = 20;

int numbers[MAX_N];
int n, target;
int solutionCount = 0;

void exhaustiveSearch() {
    int totalSubsets = 1 << n;

    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;

        cout << "Checking subset: { ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cout << numbers[i] << " ";
                sum += numbers[i];
            }
        }
        cout << "}";

        if (sum == target) {
            cout << " -> Match";
            solutionCount++;
        }

        cout << "\n";
    }
}

int main() {
    cout << "Enter number of elements (1-20): ";
    cin >> n;

    if (n < 1 || n > MAX_N) {
        cout << "Invalid number of elements.\n";
        return 1;
    }

    cout << "Enter positive integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];

        if (numbers[i] <= 0) {
            cout << "All elements must be positive integers.\n";
            return 1;
        }
    }

    cout << "Enter target sum: ";
    cin >> target;

    if (target < 0) {
        cout << "Target must be non-negative.\n";
        return 1;
    }

    cout << "\nExhaustive Search Results:\n";
    exhaustiveSearch();

    cout << "\nTotal subsets checked: " << (1 << n) << "\n";
    cout << "Total matching subsets: " << solutionCount << "\n";

    return 0;
}
