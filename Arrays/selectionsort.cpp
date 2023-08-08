#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &v){
    for (int i = 0; i < v.size()-1; i++)
    {
        int miN=i;
        for (int j = i+1; j < v.size(); j++)
        {
            if(v[j]<v[miN]){
                miN=j;
            }
        }
        swap(v[i],v[miN]);
    }
}

int main()
{
    vector <int> v= {3,2,4,9,1,0,1,95};

    selectionSort(v);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}