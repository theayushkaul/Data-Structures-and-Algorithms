#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        
        int m=matrix.size(),n=matrix[0].size();
        int srow=0,erow=m-1,scol=0,ecol=n-1;
        
        int total=m*n;
        int count=0;
        
        while(count<total){
//          First Row
            for(int i=scol;count<total && i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
//          Ending Column
            for(int i=srow;count<total && i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;
//          Ending Row
            for(int i=ecol;count<total && i>=scol;i--){
                ans.push_back(matrix[erow][i]);
                count++;
            }
            erow--;
//          Start Column
            for(int i=erow;count<total && i>=srow;i--){
                ans.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }
        
        return ans;
    }
};

int main(){

    return 0;
}