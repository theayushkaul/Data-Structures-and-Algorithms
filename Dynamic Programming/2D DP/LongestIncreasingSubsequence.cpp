//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int solveOptimal(int n, int a[]){
        if(n == 0){
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }else{
                // This is using Binary search
                // This searches in the ans array for the correct index to put the element at.
                // Lower Bound: Searches in the vector to bring smallest possible index where element is >=arr[i]; 
                int index = lower_bound(ans.begin(), ans.end(), a[i])-ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    int solveOpt(int n, int a[]){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr = n-1; curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    include = 1 + nextRow[curr+1];
                }
                int exclude = nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    int solveTab(int n, int a[]){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int curr = n-1; curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include,exclude);
            }
        }
        
        return dp[0][0];
    }
    int solveMem(int n, int a[], int curr, int prev,vector<vector<int>>& dp){
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]){
            include = 1 + solveMem(n,a,curr+1,curr,dp);
        }
        int exclude = solveMem(n,a,curr+1,prev,dp);
        
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }
    int solve(int n, int a[], int curr, int prev){
        if(curr == n){
            return 0;
        }
        
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]){
            include = 1 + solve(n,a,curr+1,curr);
        }
        int exclude = solve(n,a,curr+1,prev);
        return max(include,exclude);
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
    //   return solve(n,a,0,-1);
       
    //   vector<vector<int>> dp(n, vector<int>(n+1,-1));
       
    //   return solveMem(n,a,0,-1,dp);
    
    return solveOptimal(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends