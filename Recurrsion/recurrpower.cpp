#include<iostream>
using namespace std;

int power(int n,int e){
    if(n==1 || e==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(e%2==0){
        return power(n,e/2) * power(n,e/2);
    }
    else{
        return n * power(n,e/2)*power(n,e/2);
    }
}

int main(){
    int n=3,e=4;
    cout<<power(n,e);
    return 0;
}