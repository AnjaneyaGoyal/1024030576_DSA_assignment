#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }


    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    void printList() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void showMiddle() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle Node: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    cout << "Linked List: ";
    list.printList();

    list.showMiddle();

    return 0;
}
