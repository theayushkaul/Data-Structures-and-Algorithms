#include<bits/stdc++.h>
using namespace std;

// Link-https://www.spoj.com/problems/EKO/

bool isPossible(vector<int> woods,int n,int m,int mid){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if((woods[i]-mid)>0){
            sum+=woods[i]-mid;
        }
        if(sum>=m){
            return 1;
        }
    }
    return 0;
}

int maxheight(vector<int> woods,int n,int m){
    sort(woods.begin(),woods.end());
    int s=0,e=0,maxH;
    for(int i=0;i<n;i++){
        e=max(e,woods[i]);
    }
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(woods,n,m,mid)){
            maxH=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return maxH;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> woods;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        woods.push_back(temp);
    }

    cout<<maxheight(woods,n,m)<<endl;
    return 0;
}