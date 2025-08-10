#include <iostream>
#include <stack>
using namespace std;
int findMinimumCost(string s)
{
    if (s.length() % 2 != 0)
    {
        return -1;
    }
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}
int main()
{
    string s = "}}}}";
    int cost = findMinimumCost(s);
    if (cost == -1)
    {
        cout << "The string cannot be made valid." << endl;
    }
    else
    {
        cout << "Minimum cost to make the string valid: " << cost << endl;
    }
    return 0;
}