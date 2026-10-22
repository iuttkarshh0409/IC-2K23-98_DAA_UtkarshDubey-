
#include <iostream>
#include <utility>
using namespace std;

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partitionArray(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main() {
    int n;

    cout << "=== Quick Sort: Divide and Conquer ===\n";
    cout << "Enter the number of elements: ";

    if (!(cin >> n) || n < 0) {
        cerr << "Error: number of elements cannot be negative.\n";
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " integers:\n";

    for (int i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Error: invalid array input.\n";
            delete[] arr;
            return 1;
        }
    }

    if (n > 0) {
        quickSort(arr, 0, n - 1);
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    delete[] arr;

    return 0;
}
