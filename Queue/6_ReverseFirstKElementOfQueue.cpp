#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // code here
        stack<int> st;
        int originalK = k;
        while (k)
        {
            int x = q.front();
            st.push(x);
            q.pop();
            k--;
        }

        while (!st.empty())
        {
            int y = st.top();
            q.push(y);
            st.pop();
        }

        int a = q.size() - originalK;
        while (a)
        {
            int c = q.front();
            q.pop();
            q.push(c);
            a--;
        }
        return q;
    }
};
int main()
{   
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    Solution obj;
    queue<int> ans = obj.reverseFirstK(q, k);
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}