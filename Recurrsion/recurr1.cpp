#include<bits/stdc++.h>
using namespace std;

int factorial(int a){
    if(a==0){
        return 1;
    }
    return a*factorial(a-1);
}

int power(int x,int n){
    if(x==0){
        return 0;
    }
    if(x==1 || n==0){
        return 1;
    }
    return x*power(x,n-1);
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    int ans=fibonacci(n-1)+fibonacci(n-2);
    return ans;
}

void sayDigit(int n){
    if(n==0){
        return;
    }
    sayDigit(n/10);
    
    if(n%10==0){
        cout<<"Zero"<<" ";
    }
    else if(n%10==1){
        cout<<"One"<<" ";
    }
    else if(n%10==2){
        cout<<"Two"<<" ";
    }
    else if(n%10==3){
        cout<<"Three"<<" ";
    }
    else if(n%10==4){
        cout<<"Four"<<" ";
    }
    else if(n%10==5){
        cout<<"Five"<<" ";
    }
    else if(n%10==6){
        cout<<"Six"<<" ";
    }
    else if(n%10==7){
        cout<<"Seven"<<" ";
    }
    else if(n%10==8){
        cout<<"Eight"<<" ";
    }
    else if(n%10==9){
        cout<<"Nine"<<" ";
    }
    
    
}

int main(){
    sayDigit(890);

    return 0;
}