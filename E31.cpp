//Here's a C++ program to simulate a deque using a one-dimensional array:
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Deque {
    int arr[MAX_SIZE];
    int front, rear, size;

public:
    Deque() : front(0), rear(0), size(0) {}

    // Function to add element at the front
    void addFront(int element) {
        if (size == MAX_SIZE) {
            cout << "Deque is full. Cannot add element." << endl;
            return;
        }

        if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        arr[front] = element;
        size++;
    }

    // Function to add element at the rear
    void addRear(int element) {
        if (size == MAX_SIZE) {
            cout << "Deque is full. Cannot add element." << endl;
            return;
        }

        arr[rear] = element;
        rear = (rear + 1) % MAX_SIZE;
        size++;
    }

    // Function to delete element from the front
    int deleteFront() {
        if (size == 0) {
            cout << "Deque is empty. Cannot delete element." << endl;
            return -1;
        }

        int element = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return element;
    }

    // Function to delete element from the rear
    int deleteRear() {
        if (size == 0) {
            cout << "Deque is empty. Cannot delete element." << endl;
            return -1;
        }

        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        int element = arr[rear];
        size--;
        return element;
    }

    // Function to display deque elements
    void display() {
        if (size == 0) {
            cout << "Deque is empty." << endl;
            return;
        }

        int tempFront = front;
        for (int i = 0; i < size; i++) {
            cout << arr[tempFront] << " ";
            tempFront = (tempFront + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;

    deque.addFront(10);
    deque.addRear(20);
    deque.addFront(5);
    deque.addRear(30);

    cout << "Deque elements: ";
    deque.display();

    cout << "Deleted from front: " << deque.deleteFront() << endl;
    cout << "Deleted from rear: " << deque.deleteRear() << endl;

    cout << "Deque elements after deletion: ";
    deque.display();

    return 0;
}
/*This program demonstrates a deque implementation using a circular array. It provides functions to add elements at both ends (addFront and addRear) and delete elements from both ends (deleteFront and deleteRear). The display function is used to print the deque elements.*/
