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

    void appendNode(int val) {
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

    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current) {
            nextNode = current->next;  
            current->next = prev;      
            prev = current;            
            current = nextNode;        
        }

        head = prev;
    }

   
    void displayReversal() {
        cout << "Original Linked List: ";
        printList();
        reverseList();
        cout << "Reversed Linked List: ";
        printList();
    }
};

int main() {
    LinkedList list;

    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);
    list.appendNode(5);

    list.displayReversal();

    return 0;
}
