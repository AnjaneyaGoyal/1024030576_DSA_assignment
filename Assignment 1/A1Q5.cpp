#include <iostream>
using namespace std;

int main() {
    int r, c, a[10][10];
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++) {
        int sumRow = 0;
        for (int j = 0; j < c; j++)
            sumRow += a[i][j];
        cout << "Sum of row " << i + 1 << " = " << sumRow << endl;
    }

    for (int j = 0; j < c; j++) {
        int sumCol = 0;
        for (int i = 0; i < r; i++)
            sumCol += a[i][j];
        cout << "Sum of column " << j + 1 << " = " << sumCol << endl;
    }
}