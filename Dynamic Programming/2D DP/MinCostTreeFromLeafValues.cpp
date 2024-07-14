#include<bits/stdc++.h>
using namespace std;

class Solution {
    // max,ans
    pair<int, int> solve(int start, int end, vector<int>& arr, vector<vector<pair<int, int>>>& dp) {
        // Base case: when there's only one element in the subarray
        if (start == end) {
            return {arr[start], 0};
        }
        // If the result is already computed, return it
        if (dp[start][end].second != INT_MAX) {
            return dp[start][end];
        }
        
        pair<int, int> ans = {INT_MIN, INT_MAX};

        // Iterate through the subarray to find the minimum cost
        for (int i = start; i < end; i++) {
            pair<int, int> left = solve(start, i, arr, dp);
            pair<int, int> right = solve(i + 1, end, arr, dp);

            int temp = left.first * right.first + left.second + right.second;

            if (temp < ans.second) {
                ans.second = temp;
                ans.first = max(left.first, right.first);
            }
        }

        dp[start][end] = ans;
        return ans;
    }
    int solveTab(vector<int>& arr){
        int n = arr.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MIN, INT_MAX}));
        for(int i=0; i<n;i++){
            dp[i][i].first = arr[i];
            dp[i][i].second = 0;
        }

        for (int len = 2; len <= n; len++) {
            for (int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                pair<int, int> ans = {INT_MIN, INT_MAX};

                // Iterate through the subarray to find the minimum cost
                for (int i = start; i < end; i++) {
                    pair<int, int> left = dp[start][i];
                    pair<int, int> right = dp[i + 1][end];

                    int temp = left.first * right.first + left.second + right.second;

                    if (temp < ans.second) {
                        ans.second = temp;
                        ans.first = max(left.first, right.first);
                    }
                }

                dp[start][end] = ans;
            }
        }
        return dp[0][n-1].second;
    }
    
public:
    int mctFromLeafValues(vector<int>& arr) {
        // int n = arr.size();
        // vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MIN, INT_MAX}));

        return solveTab(arr);
    }
};

int main(){

    return 0;
}