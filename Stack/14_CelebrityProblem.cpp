#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    bool knows(vector<vector<int>> &grid, int a, int b)
    {
        if (grid[a][b] == 1)
            return true;
        else
            return false;
    }
    int celebrity(vector<vector<int>> &grid)
    {
        stack<int> st;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (knows(grid, a, b))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }

        int ans = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i != ans && grid[ans][i] == 1) // If the celebrity knows someone, they cannot be a celebrity
            {
                return -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i != ans && grid[i][ans] == 0) // If someone does not know the celebrity, they cannot be a celebrity
            {
                return -1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };
    int result = sol.celebrity(grid);
    if (result != -1)
    {
        cout << "Celebrity is person: " << result << endl;
    }
    else
    {
        cout << "No celebrity found." << endl;
    }
    return 0;
}