#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void insertAtBottom(stack<int> &st, int num)
    {
        if (st.empty())
        {
            st.push(num);
            return;
        }
        int x = st.top();
        st.pop();

        insertAtBottom(st, num);
        st.push(x);
    }
    void reverse(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        int num = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, num);
    }
};
int main()
{
    Solution sol;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original Stack: ";
    stack<int> temp = st; 
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sol.reverse(st);

    cout << "Reversed Stack: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}