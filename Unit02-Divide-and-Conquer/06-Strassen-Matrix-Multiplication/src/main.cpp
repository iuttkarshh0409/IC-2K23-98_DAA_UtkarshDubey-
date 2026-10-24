
#include <iostream>
using namespace std;

using Matrix = long long**;

Matrix createMatrix(int n) {
    Matrix A = new long long*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new long long[n]();
    }

    return A;
}

void deleteMatrix(Matrix A, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }

    delete[] A;
}

Matrix addMatrix(Matrix A, Matrix B, int n) {
    Matrix C = createMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

Matrix subtractMatrix(Matrix A, Matrix B, int n) {
    Matrix C = createMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

Matrix getQuadrant(
    Matrix A, int rowStart, int colStart, int size
) {
    Matrix Q = createMatrix(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Q[i][j] = A[rowStart + i][colStart + j];
        }
    }

    return Q;
}

Matrix strassen(Matrix A, Matrix B, int n) {
    Matrix C = createMatrix(n);

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int half = n / 2;

    Matrix A11 = getQuadrant(A, 0, 0, half);
    Matrix A12 = getQuadrant(A, 0, half, half);
    Matrix A21 = getQuadrant(A, half, 0, half);
    Matrix A22 = getQuadrant(A, half, half, half);

    Matrix B11 = getQuadrant(B, 0, 0, half);
    Matrix B12 = getQuadrant(B, 0, half, half);
    Matrix B21 = getQuadrant(B, half, 0, half);
    Matrix B22 = getQuadrant(B, half, half, half);

    Matrix T1 = addMatrix(A11, A22, half);
    Matrix T2 = addMatrix(B11, B22, half);
    Matrix M1 = strassen(T1, T2, half);

    Matrix T3 = addMatrix(A21, A22, half);
    Matrix M2 = strassen(T3, B11, half);

    Matrix T4 = subtractMatrix(B12, B22, half);
    Matrix M3 = strassen(A11, T4, half);

    Matrix T5 = subtractMatrix(B21, B11, half);
    Matrix M4 = strassen(A22, T5, half);

    Matrix T6 = addMatrix(A11, A12, half);
    Matrix M5 = strassen(T6, B22, half);

    Matrix T7 = subtractMatrix(A21, A11, half);
    Matrix T8 = addMatrix(B11, B12, half);
    Matrix M6 = strassen(T7, T8, half);

    Matrix T9 = subtractMatrix(A12, A22, half);
    Matrix T10 = addMatrix(B21, B22, half);
    Matrix M7 = strassen(T9, T10, half);

    Matrix X1 = addMatrix(M1, M4, half);
    Matrix X2 = subtractMatrix(X1, M5, half);
    Matrix C11 = addMatrix(X2, M7, half);

    Matrix C12 = addMatrix(M3, M5, half);
    Matrix C21 = addMatrix(M2, M4, half);

    Matrix X3 = subtractMatrix(M1, M2, half);
    Matrix X4 = addMatrix(X3, M3, half);
    Matrix C22 = addMatrix(X4, M6, half);

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    deleteMatrix(A11, half);
    deleteMatrix(A12, half);
    deleteMatrix(A21, half);
    deleteMatrix(A22, half);

    deleteMatrix(B11, half);
    deleteMatrix(B12, half);
    deleteMatrix(B21, half);
    deleteMatrix(B22, half);

    deleteMatrix(T1, half);
    deleteMatrix(T2, half);
    deleteMatrix(T3, half);
    deleteMatrix(T4, half);
    deleteMatrix(T5, half);
    deleteMatrix(T6, half);
    deleteMatrix(T7, half);
    deleteMatrix(T8, half);
    deleteMatrix(T9, half);
    deleteMatrix(T10, half);

    deleteMatrix(M1, half);
    deleteMatrix(M2, half);
    deleteMatrix(M3, half);
    deleteMatrix(M4, half);
    deleteMatrix(M5, half);
    deleteMatrix(M6, half);
    deleteMatrix(M7, half);

    deleteMatrix(X1, half);
    deleteMatrix(X2, half);
    deleteMatrix(X3, half);
    deleteMatrix(X4, half);

    deleteMatrix(C11, half);
    deleteMatrix(C12, half);
    deleteMatrix(C21, half);
    deleteMatrix(C22, half);

    return C;
}

Matrix multiplyStrassen(Matrix A, Matrix B, int n) {
    int paddedSize = 1;

    while (paddedSize < n) {
        paddedSize *= 2;
    }

    Matrix paddedA = createMatrix(paddedSize);
    Matrix paddedB = createMatrix(paddedSize);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            paddedA[i][j] = A[i][j];
            paddedB[i][j] = B[i][j];
        }
    }

    Matrix paddedC = strassen(paddedA, paddedB, paddedSize);
    Matrix C = createMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = paddedC[i][j];
        }
    }

    deleteMatrix(paddedA, paddedSize);
    deleteMatrix(paddedB, paddedSize);
    deleteMatrix(paddedC, paddedSize);

    return C;
}

int main() {
    int n;

    cout << "Enter the order of square matrices: ";

    if (!(cin >> n) || n <= 0 || n > 256) {
        cerr << "Error: matrix order must be between 1 and 256.\n";
        return 1;
    }

    Matrix A = createMatrix(n);
    Matrix B = createMatrix(n);

    cout << "Enter elements of Matrix A (" << n << "x" << n
         << "):\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(cin >> A[i][j])) {
                cerr << "Error: invalid matrix element.\n";
                deleteMatrix(A, n);
                deleteMatrix(B, n);
                return 1;
            }
        }
    }

    cout << "Enter elements of Matrix B (" << n << "x" << n
         << "):\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(cin >> B[i][j])) {
                cerr << "Error: invalid matrix element.\n";
                deleteMatrix(A, n);
                deleteMatrix(B, n);
                return 1;
            }
        }
    }

    Matrix C = multiplyStrassen(A, B, n);

    cout << "\nProduct Matrix (A x B):\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j];
            if (j + 1 < n) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    deleteMatrix(A, n);
    deleteMatrix(B, n);
    deleteMatrix(C, n);

    return 0;
}
