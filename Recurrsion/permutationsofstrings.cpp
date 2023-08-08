#include<bits/stdc++.h>
using namespace std;

// Here using recursion
class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        if(index>=nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i = index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,ans,index+1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,ans,index);
        return ans;
    }
};

int main(){

    return 0;
}