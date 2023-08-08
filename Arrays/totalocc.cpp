#include <bits/stdc++.h>
using namespace std;

int totalOccurences(int arr[],int n,int key){
    int ans=0;
    int start=0,end=n-1;
    // Counting left occurences
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            ans++;
            end=mid-1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    start=0;
    end=n-1;

    // Counting Right Occurences
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            ans++;
            start=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector <int> nums= {3,2,4};
    
    return 0;
}