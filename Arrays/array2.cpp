#include<bits/stdc++.h>
using namespace std;

void revaltArr(int arr[],int n){
    for (int i = 0; i < n-1; i+=2)
    {
        swap(arr[i],arr[i+1]);
    }   
}

// n=2m+1=>where m elements appear twice and 1
int findUnique(int arr[],int n){
    int unique=0;
    for (int i = 0; i < n; i++)
    {
        unique=unique^arr[i];
    }
    
    return unique;
}



int printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        if(i==n-1){
            cout<<arr[i];
            break;
        }
        cout<<arr[i]<<" , ";
    }
    cout<<endl;
}

int main(){
    int a[]={1,1,2,3,4,5,2,3,4};
    printArray(a,9);
    // revaltArr(a,10);
    // printArray(a,10);
    cout<<findUnique(a,9)<<endl;
    return 0;
}