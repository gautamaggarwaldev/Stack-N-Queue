#include <iostream>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    string FirstNonRepeating(string &s)
    {
        map<char, int> count;
        queue<char> q;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            count[ch]++;

            q.push(ch);

            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }

        return ans;
    }
};
int main()
{
    string s = "aabc";
    Solution obj;
    string ans = obj.FirstNonRepeating(s);
    cout << ans << endl;
    return 0;
}