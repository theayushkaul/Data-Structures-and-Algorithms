#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Recursive Solution
long long int countDerangements(int n) {
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    int ans = ((n-1)* ((countDerangements(n-1)%MOD)+(countDerangements(n-2)%MOD)))%MOD;

    return ans;
}

// Memoization
long long int solveMem (int n, vector<long long int>& dp){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] =  ((n-1)* ((solveMem(n-1,dp)%MOD)+(solveMem(n-2,dp)%MOD)))%MOD;
    
    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
    return solveMem(n, dp);
}

// Tabulation
long long int solveTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i-1)* ((dp[i-1]%MOD)+(dp[i-2]%MOD))%MOD)%MOD;
    }
    return dp[n];
}

// Space optimization
long long int solve(int n){
    long long int prev1 = 0;
    long long int prev2 = 1;
    for (int i = 3; i <= n; i++)
    {
        int curr = ((i-1)* ((prev1%MOD)+(prev2%MOD))%MOD)%MOD;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int main(){

    return 0;
}