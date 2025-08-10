#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    stack<int> solve(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return st;
        }
        int num = st.top();
        st.pop();

        solve(st, x);
        st.push(num);
        return st;
    }
    stack<int> insertAtBottom(stack<int> st, int x)
    {
        solve(st, x);
        return st;
    }
};
int main()
{
    Solution sol;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    int x = 4;

    stack<int> result = sol.insertAtBottom(st, x);

    cout << "Stack after inserting " << x << " at the bottom: ";
    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}