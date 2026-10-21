
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

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

int recursiveBinarySearch(
    const vector<int>& arr, int low, int high, int target
) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return recursiveBinarySearch(
            arr, mid + 1, high, target
        );
    }

    return recursiveBinarySearch(
        arr, low, mid - 1, target
    );
}

struct BenchmarkResult {
    string algorithm;
    size_t inputSize;
    int repetitions;
    double totalTimeNs;
    double averageTimeNs;
};

template <typename SearchFunction>
BenchmarkResult benchmark(
    const string& algorithm,
    const vector<int>& arr,
    const vector<int>& targets,
    SearchFunction search
) {
    volatile long long checksum = 0;

    // Warm-up calls reduce some first-run effects.
    for (int i = 0; i < 100 && i < static_cast<int>(targets.size()); ++i) {
        checksum = checksum + search(targets[i]);
    }

    const auto start = steady_clock::now();

    for (int target : targets) {
        checksum = checksum + search(target);
    }

    const auto stop = steady_clock::now();

    const double totalNs =
        duration<double, nano>(stop - start).count();

    // Keep the computed results observable.
    if (checksum == -1) {
        cerr << "Unexpected checksum.\n";
    }

    const int repetitions = static_cast<int>(targets.size());

    return {
        algorithm,
        arr.size(),
        repetitions,
        totalNs,
        totalNs / repetitions
    };
}

int main() {
    const vector<int> inputSizes = {
        1000, 5000, 10000, 50000, 100000, 500000, 1000000
    };

    const int repetitions = 20000;

    ofstream csv("data/benchmark_results.csv");

    if (!csv) {
        cerr << "Error: Could not open data/benchmark_results.csv.\n"
             << "Run the program from the project directory.\n";
        return 1;
    }

    csv << "algorithm,input_size,case,repetitions,"
           "total_time_ns,average_time_ns,theoretical_complexity\n";

    mt19937 generator(42);

    for (size_t n : inputSizes) {
        vector<int> arr(n);

        // Unique, ascending values make target positions unambiguous.
        for (size_t i = 0; i < n; ++i) {
            arr[i] = static_cast<int>(i * 2);
        }

        uniform_int_distribution<size_t> indexDistribution(0, n - 1);

        vector<int> targets;
        targets.reserve(repetitions);

        for (int i = 0; i < repetitions; ++i) {
            targets.push_back(arr[indexDistribution(generator)]);
        }

        auto iterative = benchmark(
            "IterativeBinarySearch", arr, targets,
            [&](int target) {
                return iterativeBinarySearch(arr, target);
            }
        );

        auto recursive = benchmark(
            "RecursiveBinarySearch", arr, targets,
            [&](int target) {
                return recursiveBinarySearch(
                    arr, 0, static_cast<int>(arr.size()) - 1, target
                );
            }
        );

        csv << iterative.algorithm << ',' << n
            << ",successful," << iterative.repetitions << ','
            << iterative.totalTimeNs << ','
            << iterative.averageTimeNs << ",O(log n)\n";

        csv << recursive.algorithm << ',' << n
            << ",successful," << recursive.repetitions << ','
            << recursive.totalTimeNs << ','
            << recursive.averageTimeNs << ",O(log n)\n";

        cout << "n = " << n
             << " | Iterative: " << iterative.averageTimeNs << " ns"
             << " | Recursive: " << recursive.averageTimeNs << " ns\n";
    }

    csv.close();

    cout << "\nBenchmark completed.\n";
    cout << "Results saved to data/benchmark_results.csv\n";

    return 0;
}
