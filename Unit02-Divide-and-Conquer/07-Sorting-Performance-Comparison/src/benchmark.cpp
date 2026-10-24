
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

using namespace std;
using namespace chrono;

using SortFunction = void (*)(int*, int);

// ---------------- Merge Sort ----------------

void mergeParts(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; ++p) {
        arr[p] = temp[p];
    }
}

void mergeSortRange(int arr[], int temp[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSortRange(arr, temp, left, mid);
    mergeSortRange(arr, temp, mid + 1, right);
    mergeParts(arr, temp, left, mid, right);
}

void mergeSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int* temp = new int[n];

    mergeSortRange(arr, temp, 0, n - 1);

    delete[] temp;
}

// ---------------- Quick Sort ----------------

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

void quickSortRange(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partitionArray(arr, low, high);

    quickSortRange(arr, low, pivotIndex - 1);
    quickSortRange(arr, pivotIndex + 1, high);
}

void quickSort(int arr[], int n) {
    if (n > 1) {
        quickSortRange(arr, 0, n - 1);
    }
}

// ---------------- Heap Sort ----------------

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
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ---------------- Benchmark Utilities ----------------

bool isSorted(const int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

struct Algorithm {
    const char* name;
    SortFunction sort;
};

// ---------------- Main ----------------

int main() {
    const int sizes[] = {1000, 5000, 10000, 20000};
    const int sizeCount = sizeof(sizes) / sizeof(sizes[0]);
    const int trials = 5;

    const Algorithm algorithms[] = {
        {"Merge Sort", mergeSort},
        {"Quick Sort", quickSort},
        {"Heap Sort", heapSort}
    };

    const int algorithmCount =
        sizeof(algorithms) / sizeof(algorithms[0]);

    random_device rd;
    mt19937 rng(rd());

    uniform_int_distribution<int> valueDistribution(
        -100000, 100000
    );

    ofstream csv("data/results.csv");

    if (!csv) {
        cerr << "Error: could not create data/results.csv.\n";
        cerr << "Ensure the data directory exists and run the program "
             << "from the experiment directory.\n";
        return 1;
    }

    csv << "InputSize,Algorithm,AverageTimeMicroseconds,AllRunsSorted\n";

    cout << fixed << setprecision(2);
    cout << "\nSorting Performance Comparison\n";
    cout << "Trials per input size: " << trials << "\n\n";

    cout << left << setw(12) << "Input Size"
         << setw(16) << "Algorithm"
         << setw(22) << "Avg Time (us)"
         << "Verified\n";

    cout << string(60, '-') << '\n';

    for (int s = 0; s < sizeCount; ++s) {
        int n = sizes[s];

        double* totalTimes = new double[algorithmCount]();
        bool* allSorted = new bool[algorithmCount];

        for (int a = 0; a < algorithmCount; ++a) {
            allSorted[a] = true;
        }

        for (int trial = 0; trial < trials; ++trial) {
            int* original = new int[n];

            for (int i = 0; i < n; ++i) {
                original[i] = valueDistribution(rng);
            }

            for (int a = 0; a < algorithmCount; ++a) {
                int* data = new int[n];

                for (int i = 0; i < n; ++i) {
                    data[i] = original[i];
                }

                auto start = steady_clock::now();

                algorithms[a].sort(data, n);

                auto finish = steady_clock::now();

                double elapsed =
                    duration<double, micro>(finish - start).count();

                totalTimes[a] += elapsed;

                if (!isSorted(data, n)) {
                    allSorted[a] = false;
                }

                delete[] data;
            }

            delete[] original;
        }

        for (int a = 0; a < algorithmCount; ++a) {
            double average = totalTimes[a] / trials;

            cout << left << setw(12) << n
                 << setw(16) << algorithms[a].name
                 << setw(22) << average
                 << (allSorted[a] ? "PASS" : "FAIL") << '\n';

            csv << n << ','
                << algorithms[a].name << ','
                << average << ','
                << (allSorted[a] ? "PASS" : "FAIL") << '\n';
        }

        cout << '\n';

        delete[] totalTimes;
        delete[] allSorted;
    }

    csv.close();

    cout << "Benchmark completed.\n";
    cout << "Results saved to data/results.csv\n";

    return 0;
}
