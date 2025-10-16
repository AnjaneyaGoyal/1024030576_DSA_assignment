#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class CircularDoublyList {
private:
    Node* head;

public:
    CircularDoublyList() {
        head = nullptr;
    }

    // Insert a node at the start
    void addToFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = tail->next = newNode;
        head = newNode;
    }

    // Insert a node at the end
    void addToEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Insert after a specific key
    void insertAfterNode(int key, int val) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next->prev = newNode;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Node " << key << " not found.\n";
    }

    // Insert before a specific key
    void insertBeforeNode(int key, int val) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr;
                newNode->prev = curr->prev;
                curr->prev->next = newNode;
                curr->prev = newNode;

                if (curr == head)
                    head = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Node " << key << " not found.\n";
    }

    // Delete a node by value
    void removeNode(int key) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        do {
            if (curr->data == key) {
                if (curr->next == curr) {
                    head = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    if (curr == head)
                        head = curr->next;
                }
                delete curr;
                cout << "Node " << key << " deleted.\n";
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Node " << key << " not found.\n";
    }

    // Search a node
    void findNode(int key) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        int pos = 1;
        do {
            if (curr->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            curr = curr->next;
            pos++;
        } while (curr != head);

        cout << "Node " << key << " not found.\n";
    }

    // Display the entire list
    void printList() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        cout << "List: ";
        do {
            cout << curr->data;
            curr = curr->next;
            if (curr != head)
                cout << " <-> ";
        } while (curr != head);
        cout << '\n';
    }
};

int main() {
    CircularDoublyList list;

    list.addToFront(30);
    list.addToFront(20);
    list.addToFront(10);
    list.addToEnd(40);
    list.addToEnd(50);
    list.printList();

 
    list.insertAfterNode(30, 35);
    list.printList();


    list.insertBeforeNode(10, 5);
    list.printList();

  
    list.findNode(40);

    list.removeNode(20);
    list.printList();


    list.removeNode(5);
    list.printList();

    return 0;
}
