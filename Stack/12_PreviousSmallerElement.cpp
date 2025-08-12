#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> leftSmaller(vector<int> arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> v(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
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
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = sol.leftSmaller(arr);
    cout << "Previous smaller elements: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}