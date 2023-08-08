#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<int> original,int index,vector<int> output,vector<vector<int>>& ans) {
        // Base Case agar index array ke bahar chale jaaye
        if(index>=original.size()){
            ans.push_back(output);
            return;
        }

        // Exclude kr rhe hai ek baar ek element ko
        solve(original,index+1,output,ans);
        
        // Then include kr rhe hai
        output.push_back(original[index]);
        solve(original,index+1,output,ans);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,0,output, ans);
        return ans;
    }
};