#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v){
    int n=v.size();


    for (int i = 0; i < v.size(); i++)
    {
        //Rounds 0 to n-1
        // In ith round the ith largest round gets placed in its correct place 

        bool swapped=0;
        
        for (int j = 0; j < n-i; j++)
        {
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped=1;
            }
        }
        
        // If swapped==0: The array is sorted .
        if(swapped==0){
            break;
        }
        
    }
}

int main()
{
    vector <int> v= {3,2,4,9,1,0,1,95};

    bubbleSort(v);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}