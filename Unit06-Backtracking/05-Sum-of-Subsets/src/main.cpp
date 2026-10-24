
#include <iostream>
using namespace std;

const int MAX_N = 20;

int numbers[MAX_N];
int chosen[MAX_N];
int n, target;
int solutionCount = 0;

void findSubsets(int index, int currentSum, int chosenCount) {
    if (index == n) {
        if (currentSum == target) {
            cout << "{ ";
            for (int i = 0; i < chosenCount; i++) {
                cout << chosen[i] << " ";
            }
            cout << "}\n";
            solutionCount++;
        }
        return;
    }

    // Include the current element.
    chosen[chosenCount] = numbers[index];
    findSubsets(
        index + 1,
        currentSum + numbers[index],
        chosenCount + 1
    );

    // Exclude the current element.
    findSubsets(index + 1, currentSum, chosenCount);
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

    cout << "\nSubsets with sum " << target << ":\n";
    findSubsets(0, 0, 0);

    if (solutionCount == 0) {
        cout << "No subset found.\n";
    } else {
        cout << "\nTotal subsets found: " << solutionCount << "\n";
    }

    return 0;
}
