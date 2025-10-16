#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty list";
        } else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data;
                if (temp->next != NULL) cout << "->";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    int deleteKeyOccurrences(int key) {
        int count = 0;

        while (head != NULL && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            count++;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL) {
            if (current->data == key) {
                Node* toDelete = current;
                prev->next = current->next;
                current = current->next;
                delete toDelete;
                count++;
            } else {
                prev = current;
                current = current->next;
            }
        }

        return count;
    }

    void showUpdatedListAndCount(int key) {
        cout << "Original Linked List: ";
        display();
        int count = deleteKeyOccurrences(key);
        cout << "Count: " << count << endl;
        cout << "Updated Linked List: ";
        display();
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;
    list.showUpdatedListAndCount(key);

    return 0;
}
