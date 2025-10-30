#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* link;

    Node(int val) {
        value = val;
        link = nullptr;
    }
};

class CircularList {
    Node* start;

public:
    CircularList() {
        start = nullptr;
    }

    void addNode(int val) {
        Node* node = new Node(val);

        if (start == nullptr) {
            start = node;
            node->link = start;
            return;
        }

        Node* ptr = start;
        while (ptr->link != start) {
            ptr = ptr->link;
        }
        ptr->link = node;
        node->link = start;
    }

    void showList() {
        if (start == nullptr) {
            cout << "No elements in the list.\n";
            return;
        }

        Node* ptr = start;
        cout << "List: ";
        do {
            cout << ptr->value << " ";
            ptr = ptr->link;
        } while (ptr != start);

        cout << start->value << " (head repeated)" << endl;
    }
};

int main() {
    CircularList c1;

    c1.addNode(20);
    c1.addNode(100);
    c1.addNode(40);
    c1.addNode(80);
    c1.addNode(60);

    c1.showList();

    return 0;
}
