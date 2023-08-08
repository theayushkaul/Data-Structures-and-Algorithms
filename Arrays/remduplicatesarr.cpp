#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr){
    int n=arr.size();
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

int removeDuplicates(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int t=nums.size();
        for(int i=0;i<t;i++){
            if(((i+1)<t) && (nums[i]==nums[i+1])){
                nums.erase(nums.begin()+i);
                ans++;
                i--;
            }
            t=nums.size();
       }
        int k=n-ans+1;
        return k;
}



int main()
{
    vector<int> a = {0,0,0,1,1,1,2,2,3,3,4};
    printArray(a);
    cout<<removeDuplicates(a)<<endl;
    printArray(a);
    return 0;
}