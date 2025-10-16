#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insertFront(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at front.\n";
}
void insertBack(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << val << " at end.\n";
}


void insertNear(int val, int key, bool before) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;

    if (before && head->data == key) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " before " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if ((before && temp->next && temp->next->data == key) ||
            (!before && temp->data == key)) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << (before ? " before " : " after ") << key << ".\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Node with value " << key << " not found.\n";
}


void deleteFront() {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from front.\n";
    delete temp;
}

void deleteBack() {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}

void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Deleted " << key << ".\n";
}

void findNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Found " << key << " at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << key << " not found.\n";
}


void printList() {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertFront(10);
    insertFront(5);
    insertBack(20);
    insertNear(15, 10, false);
    printList();

    deleteFront();
    deleteBack();
    deleteNode(15);
    printList();

    findNode(20);
    findNode(5);

    return 0;
}
