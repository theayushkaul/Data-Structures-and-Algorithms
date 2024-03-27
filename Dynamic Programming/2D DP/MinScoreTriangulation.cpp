#include<bits/stdc++.h>
using namespace std;
// Given a triangle: multiply every corner cost 
class Solution {
    int solveTab(vector<int>& b){
        int n = b.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = n-1;i>=0 ; i--){
            for(int j = i+2;j<n ;j++){
                int ans = INT_MAX;
                for(int k = i+1;k<j;k++){
                    ans =  min(ans, (b[i]*b[j]*b[k]+dp[k][j]+dp[i][k]));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
    int solveMem(vector<int>& b,int i,int j,vector<vector<int>>& dp){
        if(i+1 == j){ 
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            ans =  min(ans, (b[i]*b[j]*b[k]+solveMem(b,k,j,dp)+solveMem(b,i,k,dp)));
        }
        dp[i][j] = ans;
        return ans;
    }

    int solve(vector<int>& b,int i,int j){
        if(i+1 == j){
            return 0;
        }

        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            ans =  min(ans, (b[i]*b[j]*b[k]+solve(b,k,j)+solve(b,i,k)));
        }

        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveTab(values);
    }
};
int main(){

    return 0;
}