#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int st,int en){
        if(st >= en){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = st; i<=en;i++){
            int temp = i + max(solve(i+1,en), solve(st,i-1));
            ans = min(ans, temp);
        }

        return ans;
    }
    int solveMem(int st,int en,vector<vector<int>>& dp){
        if(st >= en){
            return 0;
        }
        if(dp[st][en] != -1){
            return dp[st][en];
        }

        int ans = INT_MAX;
        for(int i = st; i<=en;i++){
            int temp = i + max(solveMem(i+1,en,dp), solveMem(st,i-1,dp));
            ans = min(ans, temp);
        }

        return dp[st][en] = ans;
    }
    int solveTab(int n){
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int st = n; st>=1;st--){
            for(int en = st;en<=n;en++){
                if(st == en){
                    continue;
                }
                int ans = INT_MAX;
                for(int i = st; i<=en;i++){
                    int temp = i + max(dp[i+1][en], dp[st][i-1]);
                    ans = min(ans, temp);
                }
                dp[st][en] = ans;
            }
            }
            return dp[1][n];
        }
        
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveTab(n);
    }
};

int main(){

    return 0;
}