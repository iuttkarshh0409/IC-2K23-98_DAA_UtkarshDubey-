
#include <iostream>
using namespace std;

const int MAX_N = 20;

int numbers[MAX_N];
int chosen[MAX_N];
int n;
int target;
bool solutionFound = false;

void backtrack(int index, int currentSum) {
    // A solution is found when the target sum is reached.
    if (currentSum == target) {
        solutionFound = true;

        cout << "Subset: { ";
        for (int i = 0; i < index; i++) {
            if (chosen[i]) {
                cout << numbers[i] << " ";
            }
        }
        cout << "}\n";
        return;
    }

    // No elements remain to explore.
    if (index == n) {
        return;
    }

    // Choice 1: include the current number.
    chosen[index] = 1;
    backtrack(index + 1, currentSum + numbers[index]);

    // Backtrack: undo the previous choice.
    chosen[index] = 0;

    // Choice 2: exclude the current number.
    backtrack(index + 1, currentSum);
}

int main() {
    cout << "Enter number of elements (1-" << MAX_N << "): ";
    cin >> n;

    if (n < 1 || n > MAX_N) {
        cout << "Invalid number of elements.\n";
        return 1;
    }

    cout << "Enter positive integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];

        if (numbers[i] <= 0) {
            cout << "Only positive integers are allowed.\n";
            return 1;
        }
    }

    cout << "Enter target sum: ";
    cin >> target;

    if (target < 0) {
        cout << "Target must be non-negative.\n";
        return 1;
    }

    cout << "\nSubsets with sum " << target << ":\n";

    backtrack(0, 0);

    if (!solutionFound) {
        cout << "No matching subset found.\n";
    }

    return 0;
}
