#include <bits/stdc++.h>
using namespace std;

vector<int> mergearr(vector<int> &arr1,vector<int> &arr2){
    int i=0,j=0;
    vector<int> ans;
    
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j]){
            ans.push_back(arr2[j]);
            j++;
        }
        else{
            ans.push_back(arr2[j]);
            ans.push_back(arr1[i]);
            j++;
            i++;
        }
    }

    while(i<arr1.size()){
        ans.push_back(arr1[i]);
    }

    while(j<arr2.size()){
        ans.push_back(arr2[j]);
    }

    return ans;
}

int main()
{
    vector <int> v1= {3,2,4,9,1,0,1,95};

    vector<int> v3= mergearr(v1,v1);
    
    for (int i = 0; i < v3.size(); i++)
    {
        cout<<v3[i]<<" ";
    }
    
    return 0;
}