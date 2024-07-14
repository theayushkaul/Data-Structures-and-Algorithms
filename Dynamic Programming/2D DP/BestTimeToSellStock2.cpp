#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> prices, int index, int n, bool bought){
        if(index >= n){
            return 0;
        }
        int buy = 0,sold = 0; 
        if(!bought){
            buy = solve(prices,index + 1,n,true) - prices[index];
        }else{
            sold = solve(prices,index+1,n,false) + prices[index];
        }
        int notBought = solve(prices,index+1,n,bought);
        return max(buy,max(sold,notBought));
    }
    int solveMem(vector<int> prices, int index, bool bought, vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][bought] != -1){
            return dp[index][bought];
        }
        int buy = 0,sold = 0; 
        if(!bought){
            buy = solveMem(prices,index + 1,true,dp) - prices[index];
        }else{
            sold = solveMem(prices,index+1,false,dp) + prices[index];
        }
        int notBought = solveMem(prices,index+1,bought,dp);
        return dp[index][bought] = max(buy,max(sold,notBought));
    }
    int solveTab(vector<int> prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int index = n-1;index>=0;index--){
            for(int bought = 0;bought<2;bought++){
                int buy = 0,sold = 0; 
                if(!bought){
                    buy = dp[index + 1][true] - prices[index];
                }else{
                    sold = dp[index + 1][false] + prices[index];
                }
                int notBought = dp[index+1][bought];
                dp[index][bought] = max(buy,max(sold,notBought));
            }
        }
        return dp[0][false];
    }
    int solveOpt(vector<int> prices){
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index = n-1;index>=0;index--){
            for(int bought = 0;bought<2;bought++){
                int buy = 0,sold = 0; 
                if(!bought){
                    buy = next[true] - prices[index];
                }else{
                    sold = next[false] + prices[index];
                }
                int notBought = next[bought];
                curr[bought] = max(buy,max(sold,notBought));
            }
            next = curr;
        }
        return curr[false];
    }
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return solveMem(prices,0,false,dp);
        return solveOpt(prices);
    }
};

int main(){

    return 0;
}