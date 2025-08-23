#include <iostream>
using namespace std;

class CQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CQueue(int s) {
        arr = new int[s];
        size = s;
        front = -1;
        rear = -1;
    }

    void push(int ele) {
        // Overflow check
        if ((front == (rear + 1) % size)) {
            cout << "Overflow!" << endl;
            return;
        }
        // First element
        if (front == -1) {
            front = rear = 0;
            arr[rear] = ele;
        }
        else {
            rear = (rear + 1) % size;
            arr[rear] = ele;
        }
    }

    int pop() {
        if (front == -1) {
            cout << "Underflow! Queue is empty" << endl;
            return -1;
        }

        int data = arr[front];

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }

        return data;
    }

    int Front() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    CQueue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // should show overflow

    cout << q.pop() << endl; // 1
    cout << q.pop() << endl; // 2

    q.push(6);
    q.push(7);

     
}
