
#include <iostream>
using namespace std;

const int N = 4;

int board[N][N] = {};
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
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << '\n';
    }
    cout << '\n';
}

void solveQueens(int row) {
    if (row == N) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            // Place a queen.
            board[row][col] = 1;

            // Solve for the next row.
            solveQueens(row + 1);

            // Backtrack: remove the queen.
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "Solutions for the 4-Queens Problem:\n\n";

    solveQueens(0);

    cout << "Total solutions found: " << solutionCount << '\n';

    return 0;
}
