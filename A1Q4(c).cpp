#include <iostream>
using namespace std;

int main() {
    int a[10][10], trans[10][10], r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

     for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }


    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }
}