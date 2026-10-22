#include <iostream>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    // Merge both sorted halves.
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements.
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back into the original array.
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    // Base case.
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // Divide into two halves.
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);

    // Merge the sorted halves.
    merge(arr, temp, left, mid, right);
}

int main() {
    int n;

    cout << "=== Merge Sort: Divide and Conquer ===\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 0 || !cin) {
        cout << "Invalid number of elements.\n";
        return 1;
    }

    int* arr = new int[n];
    int* temp = new int[n];

    cout << "Enter " << n << " integers:\n";

    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cout << "Invalid array input.\n";
            delete[] arr;
            delete[] temp;
            return 1;
        }
    }

    if (n > 0) {
        mergeSort(arr, temp, 0, n - 1);
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';

    delete[] arr;
    delete[] temp;

    return 0;
}