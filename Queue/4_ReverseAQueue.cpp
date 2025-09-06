# include <iostream>
# include <queue>
# include <stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int>st;
        while(!q.empty()) {
            int x = q.front();
            st.push(x);
            q.pop();
        }
        
        while(!st.empty()) {
            int y = st.top();
            q.push(y);
            st.pop();
        }
        return q;
    }
};
int main() {
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    Solution obj;
    queue<int>ans = obj.reverseQueue(q);
    
    while(!ans.empty()) {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}