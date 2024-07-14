#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(string& s,string& p,int i,int j){
        if(i < 0 && j < 0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k = 0; k<=j;k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(s[i] == p[j] || p[j] == '?'){
            return solve(s,p,i-1,j-1);
        }else if(p[j] == '*'){
            return solve(s,p,i-1,j) || solve(s,p,i,j-1);
        }
        else{
            return false;
        }
    }
    bool solveMem(string& s,string& p,int i,int j, vector<vector<int>>& dp){
        if(i < 0 && j < 0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k = 0; k<=j;k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solveMem(s,p,i-1,j-1,dp);
        }else if(p[j] == '*'){
            return dp[i][j] = solveMem(s,p,i-1,j,dp) || solveMem(s,p,i,j-1,dp);
        }
        else{
            return false;
        }
    }
    bool solveTab(string& s, string& p){
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[0][0] = true;
        for(int j = 1;j<=p.length();j++){
            bool flag = true;
            for(int k = 0; k<j;k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
    bool solveOpt(string& s, string& p){
        vector<int> curr(p.length()+1,0);
        vector<int> prev(p.length()+1,0);
        prev[0] = true;

        for(int j = 1;j<=p.length();j++){
            bool flag = true;
            for(int k = 0; k<j;k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i=1; i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }else if(p[j-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }
                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[p.length()];
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
        // return solveMem(s,p,s.length()-1,p.length()-1,dp);
        return solveOpt(s,p);
    }
};


int main(){

    return 0;
}