#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();

    sortStack(s);
    sortedInsert(s, num);
};

int main()
{
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Original Stack: ";
    stack<int> temp = s; 
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(s);

    cout << "Sorted Stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}   
