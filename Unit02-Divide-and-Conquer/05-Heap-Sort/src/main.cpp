
#include <iostream>
#include <utility>
using namespace std;

void heapify(int arr[], int heapSize, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, heapSize, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build a max heap.
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Move the maximum element to its correct position.
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;

    cout << "=== Heap Sort ===\n";
    cout << "Enter the number of elements: ";

    if (!(cin >> n) || n < 0) {
        cerr << "Error: number of elements cannot be negative.\n";
        return 1;
    }

    // Allocate a dynamic array.
    int* arr = new int[n];

    cout << "Enter " << n << " integers:\n";

    for (int i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Error: invalid array input.\n";
            delete[] arr;
            return 1;
        }
    }

    heapSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    // Release allocated memory.
    delete[] arr;

    return 0;
}
