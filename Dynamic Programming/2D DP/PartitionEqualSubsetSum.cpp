#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool solve(vector<int>& nums, int i, int target,int sum){
        if(i >= nums.size()){
            return false;
        }
        if(sum == target){
            return true;
        }
        if(sum > target){
            return false;
        }
        
        bool include = solve(nums,i+1,target,sum+nums[i]);
        bool exclude = solve(nums,i+1,target,sum);
        
        return include || exclude;
    }
    bool solveMem(vector<int>& nums, int i, int target, int sum, vector<vector<int>>& dp) {
        if (sum == target) {
            return true;
        }
        if (i >= nums.size() || sum > target) {
            return false;
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        bool include = solveMem(nums, i + 1, target, sum + nums[i], dp);
        bool exclude = solveMem(nums, i + 1, target, sum, dp);

        return dp[i][sum] = include || exclude;
    }
    bool solveTab(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target + 1,false));
        for(int i=0; i<=n;i++){
            dp[i][0] = true;
        }
        for(int i=n-1;i>=0;i--){
            for(int t = 1;t<=target;t++){
                bool include = ((t-nums[i])<0) ? false : dp[i + 1][t - nums[i]];
                bool exclude = dp[i + 1][t];
                dp[i][t] = include || exclude;
            }
        }
        return dp[0][target];
    }
    bool solveopt(vector<int>& nums, int target){
        int n = nums.size();
        vector<bool> curr(target + 1,false);
        vector<bool> prev(target + 1,false);
        prev[0] = true;
        curr[0] = true;
        for(int i=n-1;i>=0;i--){
            for(int t = 1;t<=target;t++){
                bool include = ((t-nums[i])<0) ? false : curr[t - nums[i]];
                bool exclude = curr[t];
                prev[t] = include || exclude;
            }
            curr = prev;
        }
        return curr[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        if(sum%2 != 0){
            return false;
        }else{
            // vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
            return solve(nums, 0, sum/2, 0);
        }
    }
};
int main(){

    return 0;
}