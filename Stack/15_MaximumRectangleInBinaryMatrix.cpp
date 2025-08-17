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

    vector<int> leftSmaller(vector<int> &arr)
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
        vector<int> next = nextSmallerElement(h, n);
        vector<int> prev = leftSmaller(h);

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int len = h[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int bre = next[i] - prev[i] - 1;
            int newAr = len * bre;
            area = max(area, newAr);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1') // If the cell is '1', increase the height
                {
                    heights[j] += 1;
                }
                else // If the cell is '0', reset the height
                { 
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights)); // Calculate the maximum area for the current row's histogram
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int result = sol.maximalRectangle(matrix);
    cout << "Maximum rectangle area in binary matrix: " << result << endl;
    return 0;
}