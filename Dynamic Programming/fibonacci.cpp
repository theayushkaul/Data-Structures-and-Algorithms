#include<bits/stdc++.h>
using namespace std;

// Memoization: Top Down Approach
int fib(int n,vector<int>& dp){
        if(n<=1){
                dp[n] = n;
                return dp[n];
        }
        if(dp[n] != -1){
                return dp[n];
        }

        dp[n] = fib(n-1,dp) + fib(n-2,dp);
        return dp[n];
}

int main()
{
        int n;
        cin>>n;

        vector<int> dp(n+1);
        for(auto i: dp){
                i = -1;
        }

        cout<<fib(n,dp);

        return 0;
}