#include <iostream>
using namespace std;

void displayDiagonal(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << arr[i] << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}

void displayTriDiagonal(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << arr[n - 1 + i] << " ";
            }
            else if (i == j + 1) {
                cout << arr[i - 1] << " ";
            }
            else if (i + 1 == j) {
                cout << arr[2*n - 1 + i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

void displayLower(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << arr[i*(i+1)/2 + j] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

void displayUpper(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                cout << arr[j*(j+1)/2 + i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

void displaySymmetric(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << arr[i*(i+1)/2 + j] << " ";
            }
            else {
                cout << arr[j*(j+1)/2 + i] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    int n, choice;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    cout << "\nChoose matrix type:\n"
         << "1. Diagonal\n"
         << "2. Tri-diagonal\n"
         << "3. Lower Triangular\n"
         << "4. Upper Triangular\n"
         << "5. Symmetric\n"
         << "Enter choice: ";
    cin >> choice;

    int size = 0;
    if (choice == 1) {
        size = n;
    }
    else if (choice == 2) {
        size = 3*n - 2;
    }
    else if (choice == 3 || choice == 4 || choice == 5) {
        size = n*(n+1)/2;
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    int arr[1000];
    cout << "Enter " << size << " elements (compact form):\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nMatrix:\n";
    switch (choice) {
        case 1: {
            displayDiagonal(arr, n);
            break;
        }
        case 2: {
            displayTriDiagonal(arr, n);
            break;
        }
        case 3: {
            displayLower(arr, n);
            break;
        }
        case 4: {
            displayUpper(arr, n);
            break;
        }
        case 5: {
            displaySymmetric(arr, n);
            break;
        }
    }
    return 0;
}
