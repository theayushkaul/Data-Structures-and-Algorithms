#include<bits/stdc++.h>
using namespace std;
// Time Complexity, Space Complexity
// dp[i]: Saves the maximum sum till i by either including or excluding the ith element 
// If including we have to add nums[i] to the sum and if excluding we don't have to add anything to the sum since we are not counting that specific no. in the max sum

// Example Array: [9,4,2,9,7] => dp: [9, 9, 11, 18, 18]
// dp[0] = nums[0] = 9;
// dp[1] = max(9,4) = 9;
// dp[2] = max(11,9) = 11;
// dp[3] = max(18,11) = 18;
// dp[4] = max(18,18) = 18;


// Using Tabulation: O(n) O(n) 
int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i = 1 ; i<n ; i++){
        // Takes dp[i-2] = 0: for i<0
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl,excl);
    }

    return dp[n-1];
}
// Optimzed Space : O(n) O(1)
int solveTab(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1 ; i<n ; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl,excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

// Using Memoization:o(n) o(n)
int solveMem(vector<int> &nums, int n,vector<int>& dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int incl = solveMem(nums,n-2,dp) + nums[n];
    int excl = solveMem(nums,n-1,dp);

    dp[n] =  max(incl,excl);
    return dp[n];
}

// Using Recursion only
int solve(vector<int> &nums, int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1);

    return max(incl,excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // int ans = solve(nums,n-1);

    vector<int> dp(n,-1);
    int ans = solveMem(nums,n-1,dp);
    return ans;
}

int main(){

    return 0;
}