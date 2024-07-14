#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string word1, string word2, int i, int j) {
        // If we reach the end of word1, return the number of characters remaining in word2
        if (i == word1.length()) {
            return word2.length() - j;
        }
        // If we reach the end of word2, return the number of characters remaining in word1
        if (j == word2.length()) {
            return word1.length() - i;
        }
        
        // If characters are the same, move both pointers
        if (word1[i] == word2[j]) {
            return solve(word1, word2, i + 1, j + 1);
        }

        // Compute the cost of each operation: replace, delete, insert
        int rep = solve(word1, word2, i + 1, j + 1); // replace
        int del = solve(word1, word2, i + 1, j); // delete
        int ins = solve(word1, word2, i, j + 1); // insert

        // Return the minimum cost of the operations plus one for the current operation
        return 1 + min(rep, min(del, ins));
    }
    int solveMem(string word1, string word2, int i, int j,vector<vector<int>>& dp) {
        // If we reach the end of word1, return the number of characters remaining in word2
        if (i == word1.length()) {
            return word2.length() - j;
        }
        // If we reach the end of word2, return the number of characters remaining in word1
        if (j == word2.length()) {
            return word1.length() - i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        // If characters are the same, move both pointers
        if (word1[i] == word2[j]) {
            return dp[i][j] = solveMem(word1, word2, i + 1, j + 1,dp);
        }

        // Compute the cost of each operation: replace, delete, insert
        int rep = solveMem(word1, word2, i + 1, j + 1,dp); // replace
        int del = solveMem(word1, word2, i + 1, j,dp); // delete
        int ins = solveMem(word1, word2, i, j + 1,dp); // insert

        // Return the minimum cost of the operations plus one for the current operation
        return dp[i][j] = 1 + min(rep, min(del, ins));
    }
    int solveTab(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));
        for(int i=0;i<word1.length();i++){
            dp[i][word2.length()] = word1.length() - i;
        }
        for(int i=0;i<word2.length();i++){
            dp[word1.length()][i] = word2.length() - i;
        }

        for(int i=word1.length()-1; i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }else{    
                    int rep = dp[i + 1][j + 1]; // replace
                    int del = dp[i + 1][j]; // delete
                    int ins = dp[i][j + 1]; // insert

                    dp[i][j] = 1 + min(rep, min(del, ins));
                }

            }
        }
        return dp[0][0];
    }
    int solveOpt(string word1, string word2) {
        vector<int> curr(word2.length()+1,0);
        vector<int> next(word2.length()+1,0);

        // Base Case 1
        for(int i=0;i<word2.length();i++){
            next[i]= word2.length() - i;
        }

        for(int i=word1.length()-1; i>=0;i--){
            // Base Case 2
            curr[word2.length()] = word1.length()-i;
            for(int j=word2.length()-1;j>=0;j--){
                
                if (word1[i] == word2[j]) {
                    curr[j] = next[j + 1];
                }else{    
                    int rep = next[j + 1]; // replace
                    int del = next[j]; // delete
                    int ins = curr[j + 1]; // insert

                    curr[j] = 1 + min(rep, min(del, ins));
                }
            }
            next = curr;
        }
        return curr[0];
    }
    
public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        // return solveMem(word1, word2, 0, 0,dp);
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        return solveOpt(word1,word2);
    }
};


int main(){

    return 0;
}