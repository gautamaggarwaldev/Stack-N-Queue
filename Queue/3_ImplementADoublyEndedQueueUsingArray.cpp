# include <iostream>
# include <vector>
using namespace std;
class DeQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;
public:
    DeQueue(int s) {
        arr = new int[s];
        size = s;
        front = -1;
        rear = -1;
    }

    void pushFront(int ele) {
        if(front==0 && rear==size-1 || rear==(front-1)%(size-1) ) {
            cout << "Queue is full" << endl;
            return;
        }
        else if(front==-1) {
            front=rear=0;
        }
        else if(front==0 && rear!=size-1) {
            front=size-1;
        }
        else {
            front--;
        }
        arr[front]=ele;
    } 

    void pushRear(int ele) {
        if(front==0 && rear==size-1 || rear==(front-1)%(size-1) ) {
            cout << "Queue is full" << endl;
            return;
        }
        else if(front==-1) {
            front=rear=0;
        }
        else if(rear==size-1 && front!=0) {
            rear=0;
        }
        else {
            rear++;
        }
        arr[rear]=ele;
    }

    int popFront() {
        if(front==-1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        arr[front]=-1;
        if(front==rear) {
            front=rear=-1;
        }
        else if(front==size-1) {
            front=0;
        }
        else {
            front++;
        }
        return arr[front];
    }

    int popRear() {
        if(front==-1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        arr[rear]=-1;
        if(front==rear) {
            front=rear=-1;
        }
        else if(rear==0) {
            rear=size-1;
        }
        else {
            rear--;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front==-1;
    }

    int getFront() {
        if(front==-1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if(front==-1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};
int main() {
    DeQueue dq(5);
    dq.pushRear(1);
    dq.pushRear(2);
    dq.pushFront(3);
    dq.pushFront(4);
    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;
    dq.popFront();
    cout << dq.getFront() << endl;
    dq.popRear();
    cout << dq.getRear() << endl;
    return 0;
}