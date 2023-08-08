//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long,vector<long long>,greater<long long>> min;
        int cnt=0;
        while(cnt<n){
            min.push(arr[cnt++]);
        }
        
        long long cost=0;
        
        while(min.size()>1){
            long long mini1 = min.top();
            min.pop();
            long long mini2 = min.top();
            min.pop();
            min.push(mini1+mini2);
            cost+=mini1+mini2;
        }
        
        return cost;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
