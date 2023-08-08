#include<bits/stdc++.h>
using namespace std;
// Approach 1: Using vector
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sum;
    
    for(int i = 0;i<arr.size();i++){
        int ans = arr[i];
        sum.push_back(ans);
        for(int j=i+1;j<arr.size();j++){
            ans+=arr[j];
            sum.push_back(ans);
        }
    }
    
    sort(sum.begin(),sum.end());

    return sum[sum.size()-k];
}

// Approach 2: Using min-heap
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> sum;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        int ans = 0;
        for(int j = i;j<n;j++){
            ans+=arr[j];
            if(sum.size()<k){
                sum.push(ans);
            }
            else{
                if(ans > sum.top()){
                    sum.pop();
                    sum.push(ans);
                }
            }
        }
    }
    return sum.top();
}

int main(){

    return 0;
}