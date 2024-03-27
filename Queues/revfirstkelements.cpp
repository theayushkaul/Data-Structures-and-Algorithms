#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(queue<int>& q, int k, int cnt){
        if(q.empty()){
            return;
        }
        if(cnt >= k){
            return;
        }
        
        int num = q.front();
        q.pop();
        solve(q,k,cnt+1);
        q.push(num);
    }
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        solve(q,k,0);
        int size = q.size();
        
        for(int i = 0; i<size-k;i++){
            int num = q.front();
            q.pop();
            q.push(num);
        }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends