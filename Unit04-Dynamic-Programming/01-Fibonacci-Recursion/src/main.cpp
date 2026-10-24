
#include <iostream>

using namespace std;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Enter the Fibonacci position (0-40): ";

    if (!(cin >> n) || n < 0 || n > 40) {
        cerr << "Error: enter an integer between 0 and 40.\n";
        return 1;
    }

    cout << "Fibonacci number at position "
         << n << " is " << fibonacci(n) << '\n';

    return 0;
}
