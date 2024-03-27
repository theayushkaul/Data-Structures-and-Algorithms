#include<bits/stdc++.h>
using namespace std;

bool isPossible(int mid,vector<int> &boards, int k){
    int sum=0,painter=1;
    for(int i=0;i < boards.size();i++){
        sum+=boards[i];
        if(sum>mid){
            painter++;
            if(painter>k){
                return 0;
            }
            sum=boards[i];
        }
    }
    return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0,e=0,ans;
    
    for(int i=0;i < boards.size();i++){
        e+=boards[i];
        s=max(s,boards[i]);
    }
    
    while(s <= e){
        int mid=(s+e)/2;
        if(isPossible(mid,boards,k)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){

    return 0;
}