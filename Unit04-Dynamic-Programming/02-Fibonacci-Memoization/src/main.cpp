
#include <iostream>

using namespace std;

const int MAX_N = 40;

long long memo[MAX_N + 1];
bool calculated[MAX_N + 1] = {};

long long fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Return the result if already calculated
    if (calculated[n]) {
        return memo[n];
    }

    // Calculate once and store the result
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    calculated[n] = true;

    return memo[n];
}

int main() {
    int n;

    cout << "Enter the Fibonacci position (0-"
         << MAX_N << "): ";

    if (!(cin >> n) || n < 0 || n > MAX_N) {
        cerr << "Error: enter an integer between 0 and "
             << MAX_N << ".\n";
        return 1;
    }

    cout << "Fibonacci number at position "
         << n << " is " << fibonacci(n) << '\n';

    return 0;
}
