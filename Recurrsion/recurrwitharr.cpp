#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1,n-1);
    }
}

int arrSum(int a[],int n){
    if(n==0){
        return 0;
    }
    return a[0]+arrSum(a+1,n-1);
}

bool linearSearch(int arr[],int n,int key){
    if(n==0){
        return 0;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        return linearSearch(arr+1,n-1,key);
    }
}

bool binarySearch(int arr[],int n,int key){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    if(arr[mid]==key){
        return 1;
    }
    else if(arr[mid]<key){
        return binarySearch(arr+mid+1,n,key);
    }
    else{
        return(arr,n-mid-1,key);
    }
}


int main(){

    int a[5]={1,2,3,4,85};
    cout<<isSorted(a,5)<<endl;
    cout<<arrSum(a,5)<<" Hello :"<<linearSearch(a,5,5)<<endl;

    return 0;
}