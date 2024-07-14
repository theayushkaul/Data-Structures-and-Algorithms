#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007
// Link: https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM
// This algorithm states that if there is only 1 fence and k colors: Then there are k different ways.
// If 2 posts and k colors : Then k*(k-1) + k;
// After these base cases: Solve(n) = (k-1)solve(n-1) + (k-1)solve(n-2)
// (k-1) * solve(n-2): Same last two fences 
// (k-1) * solve(n-1): Diffrent last two fences

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

// 1LL: It is used to typecast before the overflow occurs
int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}
// Recurrsion
int solve(int n,int k){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k,mul(k,(k-1)));
    }

    return mul((k-1),add(solve(n-2, k),solve(n-1, k)));
}

// Memoization
int solveMem(int n,int k, vector<int>& dp){
    if(n == 1){
        dp[n] = k;
        return dp[n];
    }
    if(n == 2){
        dp[n] = add(k,mul(k,(k-1)));
        return dp[n];
    } 
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = mul((k-1),add(solveMem(n-2, k,dp),solveMem(n-1, k,dp)));
    return dp[n];
}

// Tabulation
int solveTab(int n,int k){
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));
    for(int i = 3;i<=n;i++){
        dp[i] = mul((k-1),add(dp[i-2],dp[i-1]));
    }
    return dp[n];
}

// Optimized Solution
int solveOptimized(int n,int k){
    int prev1 = k;
    int prev2 = add(k,mul(k,k-1));
    for(int i = 3;i<=n;i++){
        int curr =  mul((k-1),add(prev1,prev2));
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int numberOfWays(int n, int k) {
    // vector<int> dp(n+1,-1);
    return solveOptimized(n,k);
}