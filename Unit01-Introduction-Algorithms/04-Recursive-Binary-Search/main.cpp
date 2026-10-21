#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[], int low, int high, int target) {
    // Base case
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }

    return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main() {
    int n;

    cout << "Enter array size: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Error: Array size must be positive.\n";
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " sorted integers: ";

    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cout << "Error: Invalid array element.\n";
            delete[] arr;
            return 1;
        }

        if (i > 0 && arr[i] < arr[i - 1]) {
            cout << "Error: Array must be sorted in ascending order.\n";
            delete[] arr;
            return 1;
        }
    }

    int target;

    cout << "Enter target element: ";
    if (!(cin >> target)) {
        cout << "Error: Invalid target.\n";
        delete[] arr;
        return 1;
    }

    int index = recursiveBinarySearch(arr, 0, n - 1, target);

    if (index != -1) {
        cout << "Element found at index " << index << ".\n";
    } else {
        cout << "Element not found.\n";
    }

    delete[] arr;
    return 0;
}