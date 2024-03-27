#include<bits/stdc++.h>
using namespace std;

bool isPossible(int mid,vector<int> &stalls, int k){
    int sum=0,cows=1,lastPos=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPos>=mid){
            cows++;
            if(cows==k){
                return true;
            }
            lastPos=stalls[i];
        } 
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0,e=0,ans=-1;
    int maX=INT_MIN;
    for(int i=0;i<stalls.size();i++){
        maX=max(maX,stalls[i]);
    }
    e=maX;
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(mid,stalls,k)){
            ans=mid;

            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){

    return 0;
}