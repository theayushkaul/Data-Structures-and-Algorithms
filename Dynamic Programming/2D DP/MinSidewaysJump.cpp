#include<bits/stdc++.h>
using namespace std;
// LeetCode
class Solution {
    int solveTab_O(vector<int>& o){
        int n = o.size()-1;
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);
        for(int i=0;i<4;i++){
            next[i] = 0;
        }
        for(int currPos = n-1; currPos>=0; currPos--){
            for(int currLane = 1;currLane<=3 ; currLane++){
                if(o[currPos+1] != currLane){
                    curr[currLane] = next[currLane];
                }
                else{
                    int ans = 1e9;
                    // SideWays Jump
                    for(int i=1;i<=3;i++){
                        if(currLane != i && o[currPos] != i){
                        ans = min(ans,1+next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2],min(1+next[1],next[3]+1));
    }
    int solveTab(vector<int>& o){
        int n = o.size()-1;
        vector<vector<int>> dp(4,vector<int> (o.size(),1e9));
        for(int i=0;i<4;i++){
            dp[i][n] = 0;
        }
        for(int currPos = n-1; currPos>=0; currPos--){
            for(int currLane = 1;currLane<=3 ; currLane++){
                if(o[currPos+1] != currLane){
                    dp[currLane][currPos] = dp[currLane][currPos+1];
                }
                else{
                    int ans = 1e9;
                    // SideWays Jump
                    for(int i=1;i<=3;i++){
                        if(currLane != i && o[currPos] != i){
                        ans = min(ans,1+dp[i][currPos+1]);
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min(dp[2][0],min(1+dp[1][0],dp[3][0]+1));
    }
    int solveMem(vector<int>& o, int currLane, int currPos, int n,vector<vector<int>>& dp){
        if(currPos == n){
            return 0;
        }
        if(dp[currPos][currLane] != -1){
            return dp[currPos][currLane];
        }
        if(o[currPos+1] != currLane){
            dp[currPos][currLane] = solveMem(o,currLane,currPos+1,n,dp);
            return solveMem(o,currLane,currPos+1,n,dp);
        }
        else{
            int ans = INT_MAX;
            // SideWays Jump
            for(int i=1;i<=3;i++){
                if(currLane != i && o[currPos] != i){
                    ans = min(ans,1+solveMem(o,i,currPos,n,dp));
                }
            }
            dp[currPos][currLane] = ans;
            return ans;
        }
    }
    int solve(vector<int>& o, int currLane, int currPos, int n){
        if(currPos == n){
            return 0;
        }

        if(o[currPos+1] != currLane){
            return solve(o,currLane,currPos+1,n);
        }
        else{
            int ans = INT_MAX;
            // SideWays Jump
            for(int i=1;i<=3;i++){
                if(currLane != i && o[currPos] != i){
                    ans = min(ans,1+solve(o,i,currPos,n));
                }
            }
            return ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return solveTab(obstacles);
    }
};
int main(){

    return 0;
}