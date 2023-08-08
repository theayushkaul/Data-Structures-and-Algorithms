#include<string>
#include<bits/stdc++.h>
using namespace std;


//Revising Arrays Functions


int sumofarray(int arr[],int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int linearsearch(int a[],int n){
    for (int i = 0; i < 10; i++)
    {
        if (a[i]==n)
        {
            return i;
        }
        
    }
    return -1;
}

void revArr(int a[],int num){
    for (int i = 0; i < num/2; i++)
    {
        int temp=a[i];
        a[i]=a[num-i-1];
        a[num-i-1]=temp;
    }

}

int main(){
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i]=i;
    }

    // Printing an array

    for (int i = 0; i < 10; i++)
    {
    cout<<i+1<<"th term is "<<arr[i]<<endl;
    }

    // Sum of elements of an array

    cout<<sumofarray(arr,10)<<endl;
    
    // Linear Search
    int arr2[10]={11,23,45,12,65,76,38,97,100,999};
    cout<<linearsearch(arr2,97)<<endl;

    // Reversing an Array
    revArr(arr2,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr2[i]<<" , ";
    }
    cout<<endl;
    return 0;
}