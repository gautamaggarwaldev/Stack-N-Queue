#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);
            s.pop_back();
        }
        for (int i = 0; i < n; i++)
        {
            char c = st.top();
            s.push_back(c);
            st.pop();
        }
    }
};
int main()
{
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    for (char c : s)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}