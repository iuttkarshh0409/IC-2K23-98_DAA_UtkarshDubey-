
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int MAX_N = 40;

long long memo[MAX_N + 1];
bool calculated[MAX_N + 1] = {};

long long recursiveFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return recursiveFibonacci(n - 1)
         + recursiveFibonacci(n - 2);
}

long long memoizedFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (calculated[n]) {
        return memo[n];
    }

    memo[n] = memoizedFibonacci(n - 1)
            + memoizedFibonacci(n - 2);

    calculated[n] = true;
    return memo[n];
}

int main() {
    int n;

    cout << "Recursive vs Memoized Fibonacci Comparison\n";
    cout << "Enter Fibonacci position (0-" << MAX_N << "): ";

    if (!(cin >> n) || n < 0 || n > MAX_N) {
        cerr << "Error: enter an integer between 0 and "
             << MAX_N << ".\n";
        return 1;
    }

    auto startRecursive = high_resolution_clock::now();
    long long recursiveResult = recursiveFibonacci(n);
    auto endRecursive = high_resolution_clock::now();

    auto startMemoized = high_resolution_clock::now();
    long long memoizedResult = memoizedFibonacci(n);
    auto endMemoized = high_resolution_clock::now();

    double recursiveTime =
        duration<double, milli>(
            endRecursive - startRecursive
        ).count();

    double memoizedTime =
        duration<double, milli>(
            endMemoized - startMemoized
        ).count();

    cout << "\nResults\n";
    cout << "------------------------------\n";
    cout << "Recursive result: " << recursiveResult << '\n';
    cout << "Memoized result:  " << memoizedResult << '\n';

    cout << "\nExecution Time\n";
    cout << "------------------------------\n";
    cout << "Recursive: " << recursiveTime << " ms\n";
    cout << "Memoized:  " << memoizedTime << " ms\n";

    cout << "\nComplexity Comparison\n";
    cout << "Recursive time: O(2^n)\n";
    cout << "Memoized time:  O(n)\n";
    cout << "Recursive auxiliary space: O(n)\n";
    cout << "Memoized auxiliary space:  O(n)\n";

    if (recursiveResult == memoizedResult) {
        cout << "\nValidation: Both results match.\n";
    } else {
        cout << "\nValidation failed: Results differ.\n";
        return 1;
    }

    return 0;
}
