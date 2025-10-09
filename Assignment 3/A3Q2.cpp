#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (char c : str) s.push(c);

    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "Reversed: " << reverseString(input) << endl;
    return 0;
}
