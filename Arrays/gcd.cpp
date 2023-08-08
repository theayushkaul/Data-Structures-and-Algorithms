#include<bits/stdc++.h>
using namespace std;

int gCommonDivisor(int a,int b){
    
    if(a==0)
        return b;
    if(b==0)
        return a;
    
    while(a!=b){
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
        }
    }
    return a;
}

int main(){
    cout<<gCommonDivisor(24,72)<<endl;
    return 0;
}