#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Solution for sc O(1): Using Greedy Algorithm
    // Solution for sc O(n): Using 1 vector
    int solveOptimized(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n+1,0);
        for(int index = n-1;index>=0;index--){
            for(int time = 0;time<n;time++){
                int include = satisfaction[index] * (time+1) + curr[time+1];
                int exclude = 0 + curr[time];
                curr[time] = max(include,exclude);
            }
        }
        return curr[0];
    }
    // Solution for sc O(n): Using 2 vectors 
    int solveOptimized(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int index = n-1;index>=0;index--){
            for(int time = n-1;time>=0;time--){
                int include = satisfaction[index] * (time+1) + next[time+1];
                int exclude = 0 + next[time];
                curr[time] = max(include,exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index = n-1;index>=0;index--){
            for(int time = n-1;time>=0;time--){
                int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];
                dp[index][time] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int solveMem(vector<int>& satisfaction, int index, int time,vector<vector<int>>& dp){
         if(index == satisfaction.size()){
             return 0;
         }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int include = satisfaction[index] * (time+1) + solveMem(satisfaction,index+1,time+1,dp);
        int exclude = 0 + solveMem(satisfaction,index+1,time,dp);
        dp[index][time] = max(include,exclude);
        return dp[index][time];
    }
    int solve(vector<int>& satisfaction, int index, int time){
         if(index == satisfaction.size()){
             return 0;
         }

         int include = satisfaction[index] * (time+1) + solve(satisfaction,index+1,time+1);
         int exclude = 0 + solve(satisfaction,index+1,time);

         return max(include,exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        // return solve(satisfaction,0,0);

        // int n = satisfaction.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveTab(satisfaction);
        return solveOptimized(satisfaction);
    }
};

int main(){

    return 0;
}