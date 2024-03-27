#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long num,vector<int> time,int n,int m){
    long long sum=0,days=1;
    for(int i=0;i<m;i++){
        if((sum+time[i])<=num){
            sum+=time[i];
        }
        else{
            days++;
            if(time[i]>num || days>n){
                return 0;
            } 
            sum=time[i];
        }
    }
    return 1;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
//  n=no.of days ; m=no.of subjects ayush has to study
	long long maxtime = -1,s=0,e=0;
    
    for(int i=0;i<time.size();i++){
        e+=time[i];
    }
    
    while(s<=e){
        long long mid=s + (e-s)/2;
        
        if(isPossible(mid,time,n,m)){
            maxtime=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    
    return maxtime;
    
}