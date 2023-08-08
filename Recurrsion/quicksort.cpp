#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int index=0;
    int pivot=arr[s];
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=pivot){
            index++;
        }
    }

    swap(arr[s],arr[s+index]);
    int i=s,j=e;

    while(i<index && j>index){
        if(arr[j]<pivot && arr[i]>pivot){
            swap(arr[j],arr[i]);
            i++;
            j--;
        }
        else if (arr[j]<pivot && arr[i]<pivot)
        {
            i++;
        }
        else if(arr[j]>pivot && arr[i]>pivot){
            j--;
        }
        else{
            i++;
            j--;
        }
    }

    return s+index;
}

void quickSort(int *arr,int s,int e){
    // Base Case
    if(s>=e){
        return;
    }

    // Partition
    int p=partition(arr,s,e);
    // Recurrsive Call
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main() {

    int arr[] = {4,1,3,5,2};
    int n = 5;
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}