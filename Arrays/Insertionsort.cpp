#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=i-1,temp=arr[i];
        
        for(j;j>=0;j--){
        
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            
            else{
                break;
            
            }
        }
        
        arr[j+1]=temp;
        
    }
}

int main()
{
    vector <int> v= {3,2,4,9,1,0,1,95};

    insertionSort(v);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}