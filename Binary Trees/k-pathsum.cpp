#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(Node *root,int k,int& count,vector<int> path){
        
        if(root==NULL){
            return;
        }
        
        path.push_back(root->data);
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        
        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==k){
                count++;
            }
        }
        
        path.pop_back();
        
}
int sumK(Node *root,int k){
    if(root==NULL){
        return 0;
    }
        
    int count=0;
    vector<int> path;
    solve(root,k,count,path);
        
    return count;
}