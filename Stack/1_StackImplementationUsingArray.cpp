#include <iostream>
using namespace std;
class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    void push(int ele)
    {
        if (top == size - 1)
        {
            cout << "OverFlow";
        }
        else
        {
            top++;
            arr[top] = ele;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "UnderFlow";
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool empty()
    {
        if (top == -1)
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
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    cout << "Top element after pop is: " << s.peek() << endl;
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    return 0;
}