#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n, vector<int>& dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        // i is the root node
        for(int i = 1;i<=n;i++){
            ans += solve(n-i,dp)*solve(i-1,dp);
        }
        return dp[n] = ans;
    }
    int solveTab(int n){
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        // i-> number of node
        for(int i = 2;i<=n;i++){
            // j-> root Node
            int ans = 0;
            for(int j = 1;j<=i;j++){
                ans += dp[i-j]*dp[j-1];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
public:
// Structurely unique bst = catalanNumber
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solveTab(n);
    }
};
int main(){

    return 0;
}