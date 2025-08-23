#include <iostream>
#include <vector>
using namespace std;
class Queue
{
private:
    int *arr;
    int front;
    int size;
    int rear;

public:
    Queue(int s)
    {
        arr = new int[s];
        size = s;
        front = 0;
        rear = 0;
    }

    void push(int ele)
    {
        if (rear == size)
        {
            cout << "OverFlow!" << endl;
        }
        else
        {
            arr[rear] = ele;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "UnderFlow" << endl;
        }
        else
        {
            front++;
        }
    }

    int Front()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Queue q(5);
    
}