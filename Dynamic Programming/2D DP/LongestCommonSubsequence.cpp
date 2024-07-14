#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solveMem(string s1,string s2, int i, int j, vector<vector<int>>&dp){
        if (i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solveMem(s1,s2,i-1,j-1,dp);
        }else{
            return dp[i][j] = max(solveMem(s1,s2,i-1,j,dp),solveMem(s1,s2,i,j-1,dp));
        }
    }
    int solve(string s1, string s2, int i, int j){
        if (i < 0 || j < 0) {
            return 0;
        }

        if(s1[i] == s2[j]){
            return 1 + solve(s1,s2,i-1,j-1);
        }

        return max(solve(s1,s2,i-1,j),solve(s1,s2,i,j-1));
    }
    int solveTab(string s1, string s2){
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));

        for(int i=1; i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
    int solveOpt(string s1, string s2){
        int len1 = s1.length();
        int len2 = s2.length();
        vector<int>curr(len2+1,0);
        vector<int>prev(len2+1,0);

        for(int i=1; i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] =  1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return curr[len2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // return solveMem(text1,text2,text1.length()-1,text2.length()-1,dp);

        return solveOpt(text1, text2);
    }
};

int main(){

    return 0;
}