#include<bits/stdc++.h>
using namespace std;
int pivotArr(vector<int> arr, int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}

int binarySearch(vector<int> arr, int n,int s,int e ,int key)
{
    int start=s,end=e;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    return -1;
}
int findPosition(vector<int>& arr, int n, int k)
{
    int pivot=pivotArr(arr,n);
    if(arr[pivot]<=k && arr[n-1]>=k){
        return binarySearch(arr,n,pivot,n,k);
    }
    else{
        return binarySearch(arr,n,0,pivot-1,k);
    }
}

int main(){

    return 0;
}