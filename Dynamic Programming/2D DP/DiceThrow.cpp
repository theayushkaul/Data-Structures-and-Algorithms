//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long solveOpt(int dice, int faces, int target){
        vector<long long> curr(target+1,0);
        vector<long long> prev(target+1,0);
        prev[0] = 1;
        
        for(int d = 1; d <= dice;d++){
            for(int t = 1; t<= target; t++){
                long long ans = 0;
                for(int i = 1; i<=faces; i++){
                    if(t-i >= 0){
                        ans += prev[t-i];
                    }
                    else{
                        break;
                    }
                }
                curr[t] = ans;
            }
            prev = curr;
        }
        return curr[target];
    }
    long long solveTab(int dice, int faces, int target){
        vector<vector<long long>> dp(dice+1,vector<long long>(target+1,0));
        dp[0][0] = 1;
        
        for(int d = 1; d <= dice;d++){
            for(int t = 1; t<= target; t++){
                long long ans = 0;
                for(int i = 1; i<=faces; i++){
                    if(t-i >= 0){
                        ans += dp[d-1][t-i];
                    }
                    else{
                        break;
                    }
                }
                dp[d][t] = ans;
            }
        }
        return dp[dice][target];
    }
    long long solveMem(int dice, int faces, int target,vector<vector<long long>>& dp){
        if(target < 0){
            return 0;
        }
        if(dice == 0 && target != 0){
            return 0;
        }
        if(target == 0 && dice != 0){
            return 0;
        }
        if(target == 0 && dice == 0){
            return 1;
        }
        
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        
        long long ans = 0;
        for(int i = 1; i<=faces; i++){
            ans += solveMem(dice-1, faces,target-i,dp);
        }
        
        return dp[dice][target] = ans;
    }
  public:
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return solveMem(N,M,X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends