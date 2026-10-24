
#include <iostream>
using namespace std;

const int MAX_N = 15;

int board[MAX_N][MAX_N] = {};
int n;
int solutionCount = 0;

bool isSafe(int row, int col) {
    // Check the same column in previous rows.
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal.
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal.
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << '\n';
    }
    cout << '\n';
}

void solveQueens(int row) {
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            solveQueens(row + 1);

            // Backtrack: remove the queen.
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "Enter board size N (1-" << MAX_N << "): ";
    cin >> n;

    if (n < 1 || n > MAX_N) {
        cout << "Invalid board size. Enter a value from 1 to "
             << MAX_N << ".\n";
        return 1;
    }

    cout << "\nSolutions for the " << n << "-Queens Problem:\n\n";

    solveQueens(0);

    if (solutionCount == 0) {
        cout << "No solution exists for N = " << n << ".\n";
    } else {
        cout << "Total solutions found: " << solutionCount << '\n';
    }

    return 0;
}
