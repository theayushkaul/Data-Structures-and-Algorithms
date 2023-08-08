#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>>&matrix,int target){

    int rows=matrix.size();
    int cols=matrix[0].size();
    // Considering the 2d matrix to be a 1d matrix of size = rows*cols
    int s=0;
    int e=rows*cols-1;

    while(s<=e){

        int mid=(s+e)/2;

        int element=matrix[mid/cols][mid%cols];

        if(element == target){
            return 1;
        }
        else if(element<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }

    }

    return 0;

}

bool linearSearch2d(int n, int a[][3], int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    // int n;
    // cin>>n;
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    // cout<<linearSearch2d(n,a,n);

    // Row-Wise Sum
    int maX=-1;
    for(int i=0;i<3;i++){
        int sumr=0;
        for(int j=0;j<3;j++){
            sumr+=a[i][j];
        }
        maX=max(maX,sumr);
        cout<<sumr<<endl;
    }
    cout<<"Max row sum is : "<<maX<<endl;
    return 0;
}