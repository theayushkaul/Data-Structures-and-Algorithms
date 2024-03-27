#include<bits/stdc++.h>
using namespace std;

// Memoization: Top Down Approach
int fib(int n, vector<int>& dp){
    if(n <= 1){
        dp[n] = n;
        return dp[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1); // Initialize a vector to store memoized values, all set to -1 initially.
    cout << fib(n, dp); // Call the fib function with memoization.
    return 0;
}
