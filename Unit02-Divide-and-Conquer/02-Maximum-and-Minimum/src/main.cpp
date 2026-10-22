
#include <iostream>
using namespace std;

struct MinMax {
    int minimum;
    int maximum;
};

MinMax findMinMax(int arr[], int low, int high) {
    // Base case: one element
    if (low == high) {
        return {arr[low], arr[low]};
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            return {arr[low], arr[high]};
        }
        return {arr[high], arr[low]};
    }

    // Divide
    int mid = low + (high - low) / 2;

    // Conquer
    MinMax left = findMinMax(arr, low, mid);
    MinMax right = findMinMax(arr, mid + 1, high);

    // Combine
    return {
        min(left.minimum, right.minimum),
        max(left.maximum, right.maximum)
    };
}

int main() {
    int n;

    cout << "=== Maximum and Minimum: Divide and Conquer ===\n";
    cout << "Enter the number of elements: ";

    if (!(cin >> n) || n <= 0) {
        cerr << "Error: number of elements must be positive.\n";
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " integers:\n";

    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cerr << "Error: invalid array input.\n";
            delete[] arr;
            return 1;
        }
    }

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << result.minimum << '\n';
    cout << "Maximum element: " << result.maximum << '\n';

    delete[] arr;

    return 0;
}
