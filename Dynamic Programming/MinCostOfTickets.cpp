#include<bits/stdc++.h>
using namespace std;
// Classy Question to be asked in interviews

// Space Optimized Solution
int minCoins(int n,vector<int> days, vector<int> cost){
    int ans = 0;
    // Monthly queue can't go above 30 and weekly queue can't go above 7. So it is considered to be constant space.
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for(int day: days){
        // step 1: remove expired days
        while(!month.empty() && month.front().first+30 <= day){
            month.pop();
        }

        while(!week.empty() && week.front().first+7 <= day){
            week.pop();
        }

        // Step 2: Add cost for current day
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        // Step 3: Ans update
        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

int solveMem(int n, vector<int>& days, vector<int>& cost, vector<int>& dp,int index){
    // Base Case
    if(index>=n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
    // 1 day pass
    int option1 = cost[0] + solveMem(n,days,cost,dp,index+1);
    
    int i;
    // 7 days pass
    for (i = 0; i < n && days[i] < days[index]+7; i++);
    int option2 = cost[1] + solveMem(n,days,cost,dp,i);
    
    // 30 days pass
    for (i = 0; i < n && days[i] < days[index]+30; i++);
    int option3 = cost[2] + solveMem(n,days,cost,dp,i);

    dp[index] = min(option1,min(option2,option3));

    return dp[index];
}

int solveTab(int n, vector<int>& days, vector<int>& cost){
    // Base Case
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;

    for (int i = n-1; i >= 0; i--)
    {
     // 1 day pass
    int option1 = cost[0] + dp[i+1];
    
    int j;
    // 7 days pass
    for (j = 0; j < n && days[j] < days[i]+30; j++);
    int option2 = cost[1] + dp[j];
    
    // 30 days pass
    for (j = 0; j < n && days[j] < days[i]+30; j++);
    int option3 = cost[2] + dp[j];

    dp[i] = min(option1,min(option2,option3));   
    }

    return dp[0];
}

int solve(int n, vector<int>& days, vector<int>& cost, int index){

    // Base Case
    if(index>=n){
        return 0;
    }
    // 1 day pass
    int option1 = cost[0] + solve(n,days,cost,index+1);
    
    int i;
    // 7 days pass
    for (i = 0; i < n && days[i] < days[index]+7; i++);
    int option2 = cost[1] + solve(n,days,cost,i);
    
    // 30 days pass
    for (i = 0; i < n && days[i] < days[index]+30; i++);
    int option3 = cost[2] + solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost){
    // return solve(n,days, cost, 0);
    // vector<int> dp(n+1,-1);
    // return solveMem(n,days,cost,dp,0);
    return solveTab(n,days,cost);
}

int main(){

    return 0;
}