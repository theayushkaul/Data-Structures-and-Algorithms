#include <bits/stdc++.h>
using namespace std;
// Given a number N. Find the minimum number of squares of any number that sums to N.
int solve(int n)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        ans = min(ans, solve(n - i * i) + 1);
    }
    return ans;
}

int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        ans = min(ans, solveMem(n - i * i, dp) + 1);
    }
    dp[n] = ans;
    return dp[n];
}

int solveTab(int n)
{
     vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sqrt(n); j++)
        {
            if(i-j*j >= 0){
                dp[i] = min(dp[i], dp[i - j * j]+1);
            }
        }
    }
    return dp[n];
}

int MinSquares(int n)
{
    return solve(n);
    vector<int> dp(n + 1, -1);
    return solveMem(n, dp);
    return solveTab(n);
}

int main()
{

    return 0;
}