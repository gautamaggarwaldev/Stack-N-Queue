#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> v(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= arr[i])
        {
            st.pop();
        }
        v[i] = st.top();
        st.push(arr[i]);
    }
    return v;
}
int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();
    vector<int> result = nextSmallerElement(arr, n);
    cout << "Next smaller elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}