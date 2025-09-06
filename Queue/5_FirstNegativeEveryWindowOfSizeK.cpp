#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        // Process first window
        for (int i = 0; i < k; i++)
        {
            if (arr[i] < 0)
            {
                dq.push_back(i);
            }
        }
        // Store answer of first window
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        // Process rest of the windows
        for (int i = k; i < n; i++)
        {
            if (!dq.empty() && i - dq.front() >= k) // Remove elements out of the current window
            {
                dq.pop_front();
            }
            if (arr[i] < 0) // Add current element if it is negative
            {
                dq.push_back(i);
            } 
            // Store answer of current window
            if (dq.size() > 0)
            {
                ans.push_back(arr[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    Solution obj;
    vector<int> ans = obj.firstNegInt(arr, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}