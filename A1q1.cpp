#include <iostream>
using namespace std;

#define MAX 100

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    int pos, value;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    if (pos < 0 || pos > n || n >= MAX) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter value to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << "Not found!\n";
}

int main() {
    int arr[MAX], n = 0, choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createArray(arr, n); break;
        case 2: displayArray(arr, n); break;
        case 3: insertElement(arr, n); break;
        case 4: deleteElement(arr, n); break;
        case 5: linearSearch(arr, n); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}