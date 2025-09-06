#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    queue<int> rearrangeQueue(queue<int> q)
    {
        queue<int> nq;

        int n = q.size() / 2;
        while (n)
        {
            int x = q.front();
            nq.push(x);
            q.pop();
            n--;
        }

        while (!nq.empty())
        {
            int y = nq.front();
            int z = q.front();
            q.push(y);
            q.push(z);
            nq.pop();
            q.pop();
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
    q.push(6);
    Solution obj;
    queue<int> ans = obj.rearrangeQueue(q);
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}