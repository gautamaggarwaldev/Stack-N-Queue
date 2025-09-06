#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int solve(vector<int> &arr, int n, int k)
{
    deque<int> maxq;
    deque<int> minq;

    for (int i = 0; i < k; i++)
    {
        while (!maxq.empty() && arr[maxq.back()] <= arr[i])
        {
            maxq.pop_back();
        }
        while (!minq.empty() && arr[minq.back()] >= arr[i])
        {
            minq.pop_back();
        }

        maxq.push_back(i);
        minq.push_back(i);
    }

    int ans = 0;
    ans += arr[maxq.front()] + arr[minq.front()];
    for (int i = k; i < n; i++)
    {

        while (!maxq.empty() && i - maxq.front() >= k)
        {
            maxq.pop_front();
        }

        while (!minq.empty() && i - minq.front() >= k)
        {
            minq.pop_front();
        }

        while (!maxq.empty() && arr[maxq.back()] <= arr[i])
        {
            maxq.pop_back();
        }
        while (!minq.empty() && arr[minq.back()] >= arr[i])
        {
            minq.pop_back();
        }

        maxq.push_back(i);
        minq.push_back(i);
        ans += arr[maxq.front()] + arr[minq.front()];
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = arr.size();
    cout << solve(arr, n, k) << endl;
    return 0;
}