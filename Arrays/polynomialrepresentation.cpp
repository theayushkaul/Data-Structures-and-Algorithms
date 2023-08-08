#include<bits/stdc++.h>
using namespace std;

class term{
    public:
        int coefficient,exponent;
};

class polynomial{
    public:
        int data;
        term* t;
};

int main(){

    int n;
    cout<<"Enter the number of non-zero terms in the polynomial: "<<endl;
    cin>>n;

    polynomial p;
    p.t=new term[n];
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the Coefficient and exponent of "<<i+1<<" th term: "<<endl;
        cin>>p.t[i].coefficient>>p.t[i].exponent;
    }

    cout<<"Enter the number you want to evaluate the expression for: "<<endl;
    cin>>p.data;
    
    int sum=0;
    
    for (int i = 0; i < n; i++)
    {
        sum+=p.t[i].coefficient*pow(p.data,p.t[i].exponent);
    }

    cout<<"The value of the polynomial at x= "<<p.data<<" is: "<<sum<<endl;
    
    return 0;
}