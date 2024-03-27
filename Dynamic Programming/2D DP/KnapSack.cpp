#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &weight, vector<int> &value, int i, int maxWeight)
{
    if (i == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0, exclude;
    //  Including the element
    if (weight[i] <= maxWeight)
    {
        include = value[i] + solve(weight, value, i - 1, maxWeight - weight[i]);
    }
    //  Excluding the element
    exclude = solve(weight, value, i - 1, maxWeight);

    return max(include, exclude);
}

int solveMem(vector<int> &weight, vector<int> &value, vector<vector<int>> &dp, int i, int W)
{
    if (i == 0)
    {
        if (weight[0] <= W)
        {
            dp[0][W] = value[0];
            return dp[0][W];
        }
        else
        {
            return 0;
        }
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    int include = 0, exclude;
    //  Including the element
    if (weight[i] <= W)
    {
        include = value[i] + solveMem(weight, value, dp, i - 1, W - weight[i]);
    }
    //  Excluding the element
    exclude = solveMem(weight, value, dp, i - 1, W);
    dp[i][W] = max(include, exclude);
    return dp[i][W];
}

int solveTab(vector<int> &weight, vector<int> &value, int i, int W)
{
    vector<vector<int>> dp(i, vector<int>(W + 1, 0));
    // Base Case
    for (int w = weight[0]; w <= W; w++)
    {
        if (weight[0] <= W)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    // See to all other cases

    for (int index = 1; index < i; index++)
    {
        for (int w = 0; w <= W; w++)
        {
            int include = 0, exclude;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            exclude = dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[i - 1][W];
}

// Space Optimized solution: Using 2 arrays
int solveOptimized(vector<int> &weight, vector<int> &value, int i, int W)
{
    vector<int> prev(W+1,0);
    vector<int> curr(W+1,0);
    // Base Case
    for (int w = weight[0]; w <= W; w++)
    {
        if (weight[0] <= W)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    for (int index = 1; index < i; index++)
    {
        for (int w = 0; w <= W; w++)
        {
            int include = 0, exclude;
            if (weight[index] <= w)
            {
                include = value[index] + prev[w - weight[index]];
            }
            exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[W];
}

// Space Optimized solution: Using 1 array
int solveOptimized(vector<int> &weight, vector<int> &value, int i, int W)
{
    vector<int> curr(W+1,0);
    // Base Case
    for (int w = weight[0]; w <= W; w++)
    {
        if (weight[0] <= W)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    for (int index = 1; index < i; index++)
    {
        for (int w = W; w >= 0; w--)
        {
            int include = 0, exclude;
            if (weight[index] <= w)
            {
                include = value[index] + curr[w - weight[index]];
            }
            exclude = curr[w];
            curr[w] = max(include, exclude);
        }
    }
    return curr[W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return solve(weight,value,n-1,maxWeight);
    // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // return solveMem(weight, value, dp, n-1, maxWeight);
    // return solveTab(weight, value, n, maxWeight);
    return  solveOptimized(weight, value, n, maxWeight);
}