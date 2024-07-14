#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveMem(vector<int> prices, int index, bool bought, vector<vector<vector<int>>>& dp,int limit){
        if(index >= prices.size()){
            return 0;
        }
        if(limit == 0){
            return 0;
        }
        if(dp[index][bought][limit] != -1){
            return dp[index][bought][limit];
        }
        int buy = 0,sold = 0; 
        if(!bought){
            buy = solveMem(prices,index + 1,true,dp,limit) - prices[index];
        }else{
            sold = solveMem(prices,index+1,false,dp,limit-1) + prices[index];
        }
        int notBought = solveMem(prices,index+1,bought,dp,limit);
        return dp[index][bought][limit] = max(buy,max(sold,notBought));
    }
    int solveOpt(vector<int> prices){
        int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int index = n-1;index>=0;index--){
            for(int bought = 0;bought<2;bought++){
                for(int limit = 2; limit>0;limit--){
                    int buy = 0,sold = 0; 
                    if(!bought){
                        buy = next[true][limit] - prices[index];
                    }else{
                        sold = next[false][limit-1] + prices[index];
                    }
                    int notBought = next[bought][limit];
                    curr[bought][limit] = max(buy,max(sold,notBought));
                }
            }
            next = curr;
        }
        return curr[false][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        return solveOpt(prices);
    }
};

int main(){

    return 0;
}