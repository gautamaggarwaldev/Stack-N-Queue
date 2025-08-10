#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &st, int N, int count)
{
    if (count == N / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    solve(st, N, count + 1);
    st.push(num);
}
void deleteMiddle(stack<int> &st, int N)
{
    int count = 0;
    solve(st, N, count);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int N = st.size();
    deleteMiddle(st, N);

    cout << "Stack after removing middle element: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}