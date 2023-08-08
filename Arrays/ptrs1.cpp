#include<bits/stdc++.h>
using namespace std;

// Revising Pointers
// Call By value and Call By Reference

int main(){

    int num=5;
    int *ptr=&num;

    cout<<*ptr<<" <=*ptr and num => "<<num<<" will print the same thing i.e the value "<<endl;
    cout<<ptr<<" <=ptr and &num => "<<&num<<" will print the same thing i.e the address where the value is being stored."<<endl;

    // The size of a ptr is 8 bytes
    cout<<"size of ptr : "<<sizeof(*ptr)<<endl;

    cout<<endl;
    // ptr with arrays
    int arr[10]={0};

    //Address of integer array  
    cout<<"arr: "<<arr<<endl;
    cout<<"&arr[0] : "<<&arr[0]<<endl;
    cout<<"&arr : "<<&arr<<endl;

    cout<<endl;
    // cout doesn't work same with the character arrays
    char c[10]="helloayus";
    cout<<"c: "<<c<<endl;
    cout<<"&c[0] : "<<&c[0]<<endl;
    cout<<"&c : "<<&c<<endl;

    cout<<endl;
    // Reference Variables
    int i=5;
    int &j=i;
    cout<<"Value of i and j are equal we can use either i or j to perform operations :  "<<i<<" , "<<j<<endl;

    return 0;
}