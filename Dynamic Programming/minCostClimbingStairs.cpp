#include <bits/stdc++.h>
using namespace std;
// using only recursion
// class Solution {

// public:
// int solve(vector<int>& cost,int n){
//     if(n == 0){
//         return cost[0];
//     }
//     if(n == 1)
//         return cost[1];
//     int ans = cost[n] + min(solve(cost,n-1), solve(cost,n-2));
//     return ans;
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int ans = min(solve(cost,n-1),solve(cost,n-2));
//         return ans;
//     }
// };

// using recurrsion and memoization

class Solution
{

public:
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return cost[0];
        }
        if (n == 1)
        {
            return cost[1];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};

// Tabulation Method:

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n <= 1) {
        return 0; // No cost if there are 0 or 1 steps.
    }
    
    // Create a DP array to store the minimum cost to reach each step.
    vector<int> dp(n);
    
    // Initialize the DP array for the first two steps.
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    // Calculate the minimum cost for each step starting from the third step.
    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    
    // The minimum cost to reach the top floor will be the minimum of the last two steps.
    return min(dp[n-1], dp[n-2]);
}

// Space Optimized
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n <= 1) {
        return 0; // No cost if there are 0 or 1 steps.
    }
    
    int prev1 = cost[0]; // Minimum cost to reach the first step.
    int prev2 = cost[1]; // Minimum cost to reach the second step.
    
    // Calculate the minimum cost for each step starting from the third step.
    for (int i = 2; i < n; i++) {
        int current = cost[i] + min(prev1, prev2);
        prev1 = prev2;
        prev2 = current;
    }
    
    // The minimum cost to reach the top floor will be the minimum of the last two steps.
    return min(prev1, prev2);
}


int main()
{
    return 0;
}