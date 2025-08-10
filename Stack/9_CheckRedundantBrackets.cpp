#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ')')
                {
                    bool flag = true;
                    while (st.top() != '(')
                    {
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            flag = false;
                        }
                        st.pop();
                    }
                    if (flag)
                        return true;
                    st.pop();
                }
            }
        }
        return false;
    }
};

int main()
{   
    Solution sol;
    string s = "((a+b))";
    if (sol.checkRedundancy(s))
    {
        cout << "The expression has redundant brackets." << endl;
    }
    else
    {
        cout << "The expression does not have redundant brackets." << endl;
    }
    return 0;
}