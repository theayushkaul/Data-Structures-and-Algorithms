#include <bits/stdc++.h>
using namespace std;

// To store data, i and j value of the array 
class node{
    public:
        int data,i,j;
        node(int data,int row,int col){
            this->data = data;
            i=row;
            j=col;
        }
};

// User-defined Comparator
class compare{
    public:
        bool operator()(node*a, node* b){
            return a->data>b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Min-Heap to store first element of k vectors
    priority_queue<node*,vector<node*>,compare> mini;
    vector<int> ans;

    // Initializing minheap
    for(int i=0;i<k;i++){
        node* temp = new node(kArrays[i][0],i,0);
        mini.push(temp);
    }
    
    // pushing in ans: In every traversal a minimum element gets pushed in the ans array
    while(!mini.empty()){
        node* temp = mini.top();
        mini.pop();
        
        int i = temp->i;
        int j = temp->j;
        
        if(j<kArrays[i].size()-1){
            node* next = new node(kArrays[i][j+1],i,j+1);
            mini.push(next);
        }
        
        ans.push_back(temp->data);
    }
    
    return ans;
}
