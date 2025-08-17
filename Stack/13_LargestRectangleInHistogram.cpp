#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            v[i] = st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> leftSmaller(vector<int> arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> v(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            v[i] = st.top();
            st.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int> &h)
    {
        int n = h.size();
        vector<int> next(n);
        next = nextSmallerElement(h, n);
        vector<int> prev(n);
        prev = leftSmaller(h);

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int len = h[i];
            if (next[i] == -1) // If there is no next smaller element, set it to n
            {
                next[i] = n;
            }
            {
                next[i] = n;
            }
            int bre = next[i] - prev[i] - 1;
            int newAr = len * bre;
            area = max(area, newAr);
        }
        return area;
    }
};
int main()
{
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = sol.largestRectangleArea(heights);
    cout << "Largest rectangle area in histogram: " << result << endl;
    return 0;
}