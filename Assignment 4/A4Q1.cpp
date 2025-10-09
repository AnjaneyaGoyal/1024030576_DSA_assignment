#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return (front == -1);
    }

    bool isFull() const {
        return (rear == capacity - 1);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }


        if (isEmpty())
            front = 0;

        arr[++rear] = item;
        cout << item << " enqueued into queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Dequeued item: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void peek() const {
        if (isEmpty())
            cout << "Queue is empty!" << endl;
        else
            cout << "Front element: " << arr[front] << endl;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter maximum queue size: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    do {
        cout << "1. Enqueue\n 2. Dequeue\n 3. Check Empty\n 4. Check Full\n 5. Display\n 6. Peek \n 7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
            break;

        case 4:
            cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
            break;

        case 5:
            q.display();
            break;

        case 6:
            q.peek();
            break;

        case 7:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid" << endl;
        }
    } while (choice != 7);

    return 0;
}
