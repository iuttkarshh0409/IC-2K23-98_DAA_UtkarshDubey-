
#include <iostream>
using namespace std;

const int CAPACITY = 100;

void display(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << (i + 1 == size ? '\n' : ' ');
    }
}

void insertElement(int arr[], int& size, int position, int value) {
    if (size == CAPACITY) {
        cout << "Insertion failed: array is full.\n";
        return;
    }

    if (position < 0 || position > size) {
        cout << "Insertion failed: invalid position.\n";
        return;
    }

    for (int i = size; i > position; --i) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    ++size;

    cout << "Element inserted successfully.\n";
}

void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Deletion failed: invalid position.\n";
        return;
    }

    for (int i = position; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    --size;
    cout << "Element deleted successfully.\n";
}

int searchElement(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

void updateElement(int arr[], int size, int position, int value) {
    if (position < 0 || position >= size) {
        cout << "Update failed: invalid position.\n";
        return;
    }

    arr[position] = value;
    cout << "Element updated successfully.\n";
}

int main() {
    int arr[CAPACITY];
    int size;

    cout << "Enter initial array size (0-" << CAPACITY << "): ";

    if (!(cin >> size) || size < 0 || size > CAPACITY) {
        cerr << "Error: invalid array size.\n";
        return 1;
    }

    cout << "Enter " << size << " elements: ";

    for (int i = 0; i < size; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Error: invalid array element.\n";
            return 1;
        }
    }

    int choice;

    do {
        cout << "\n--- Array Operations Menu ---\n"
             << "1. Display\n"
             << "2. Insert\n"
             << "3. Delete\n"
             << "4. Search\n"
             << "5. Update\n"
             << "0. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cerr << "Error: invalid menu input.\n";
            return 1;
        }

        int position, value;

        switch (choice) {
            case 1:
                display(arr, size);
                break;

            case 2:
                cout << "Enter zero-based insertion position and value: ";
                if (!(cin >> position >> value)) {
                    cerr << "Error: invalid input.\n";
                    return 1;
                }
                insertElement(arr, size, position, value);
                break;

            case 3:
                cout << "Enter zero-based deletion position: ";
                if (!(cin >> position)) {
                    cerr << "Error: invalid input.\n";
                    return 1;
                }
                deleteElement(arr, size, position);
                break;

            case 4:
                cout << "Enter value to search: ";
                if (!(cin >> value)) {
                    cerr << "Error: invalid input.\n";
                    return 1;
                }
                position = searchElement(arr, size, value);
                if (position == -1) {
                    cout << "Element not found.\n";
                } else {
                    cout << "Element found at index " << position << ".\n";
                }
                break;

            case 5:
                cout << "Enter zero-based position and new value: ";
                if (!(cin >> position >> value)) {
                    cerr << "Error: invalid input.\n";
                    return 1;
                }
                updateElement(arr, size, position, value);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
