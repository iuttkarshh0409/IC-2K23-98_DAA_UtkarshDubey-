
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter array size: ";
    if (!(cin >> n) || n <= 0 || n > 100) {
        cerr << "Error: Array size must be between 1 and 100.\n";
        return 1;
    }

    int arr[100];

    cout << "Enter " << n << " sorted integers: ";

    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cerr << "Error: Invalid array element.\n";
            return 1;
        }

        if (i > 0 && arr[i] < arr[i - 1]) {
            cerr << "Error: Array must be sorted.\n";
            return 1;
        }
    }

    int target;

    cout << "Enter target element: ";
    if (!(cin >> target)) {
        cerr << "Error: Invalid target.\n";
        return 1;
    }

    int index = binarySearch(arr, n, target);

    if (index != -1) {
        cout << "Element found at index " << index << ".\n";
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}
