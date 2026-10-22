
#include <iostream>
using namespace std;

// Recursive binary search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);
    }

    return binarySearch(arr, mid + 1, high, target);
}

int main() {
    int n;

    cout << "=== Divide and Conquer: Binary Search ===\n";
    cout << "Enter the number of elements: ";

    if (!(cin >> n) || n <= 0) {
        cerr << "Error: number of elements must be positive.\n";
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " elements in sorted order:\n";

    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cerr << "Error: invalid array input.\n";
            delete[] arr;
            return 1;
        }
    }

    // Check whether the array is sorted
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            cerr << "Error: array must be sorted.\n";
            delete[] arr;
            return 1;
        }
    }

    int target;

    cout << "Enter the element to search: ";

    if (!(cin >> target)) {
        cerr << "Error: invalid search element.\n";
        delete[] arr;
        return 1;
    }

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result << '\n';
        cout << "Position (1-based): " << result + 1 << '\n';
    } else {
        cout << "Element not found in the array.\n";
    }

    delete[] arr;
    return 0;
}
