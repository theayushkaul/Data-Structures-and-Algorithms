#include <bits/stdc++.h>
using namespace std;

class Solution{
    // SolveTab: With Space Optimization => SC:O(1)
    int solveSO1(int n,int m, vector<vector<int>>& mat,int& maxi){
        vector<int> curr(m+1,0); //Dp[i]: Curr row
        vector<int> next(m+1,0); //Dp[i+1]: Next row
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
               int right = curr[j+1];
                int down = next[j];
                int diagonal = next[j+1];
        
                if(mat[i][j] == 1){
                    curr[j] = min(right,min(down,diagonal)) + 1;
                    maxi = max(maxi,curr[j]);
                }else{
                    curr[j] = 0;
                } 
            }
            // After every iteration the current vector will become the next next vector
            next = curr;
        }
        
        return next[0];
    }
    // SolveTab: With Space Optimization => SC:O(m)
    int solveSO2(int n,int m, vector<vector<int>>& mat,int& maxi){
        vector<int> curr(m+1,0); //Dp[i]: Curr row
        vector<int> next(m+1,0); //Dp[i+1]: Next row
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
               int right = curr[j+1];
                int down = next[j];
                int diagonal = next[j+1];
        
                if(mat[i][j] == 1){
                    curr[j] = min(right,min(down,diagonal)) + 1;
                    maxi = max(maxi,curr[j]);
                }else{
                    curr[j] = 0;
                } 
            }
            // After every iteration the current vector will become the next next vector
            next = curr;
        }
        
        return next[0];
    }
    // Solve Tabulation: Without Space optimization => SC: O(m*n) 
    int solveTab(int n,int m, vector<vector<int>>& mat,int& maxi){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
               int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
        
                if(mat[i][j] == 1){
                    dp[i][j] = min(right,min(down,diagonal)) + 1;
                    maxi = max(maxi,dp[i][j]);
                }else{
                    dp[i][j] = 0;
                } 
            }
        }
        
        return dp[0][0];
    }
    
    int solveMem(int n,int m, vector<vector<int>>& mat,int i,int j,int& maxi,vector<vector<int>>& dp){
        if(i>= n || j >= m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solveMem(n,m, mat,i,j+1,maxi,dp);
        int down = solveMem(n,m,mat,i+1,j,maxi,dp);
        int diagonal = solveMem(n,m,mat,i+1,j+1,maxi,dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = min(right,min(down,diagonal)) + 1;
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }else{
            return dp[i][j] = 0;
        }
    }
    
    int solve(int n,int m, vector<vector<int>> mat,int i,int j,int& maxi){
        if(i>= n || j >= m){
            return 0;
        }
        int right = solve(n,m, mat,i,j+1,maxi);
        int down = solve(n,m,mat,i+1,j,maxi);
        int diagonal = solve(n,m,mat,i+1,j+1,maxi);
        if(mat[i][j] == 1){
            int ans = min(right,min(down,diagonal)) + 1;
            maxi = max(maxi,ans);
            return ans;
        }else{
            return 0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // int maxi = 0;
        // solve(n,m, mat,0,0,maxi);
        // return maxi;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = 0;
        solveMem(n,m,mat,0,0,maxi,dp);
        return maxi;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
