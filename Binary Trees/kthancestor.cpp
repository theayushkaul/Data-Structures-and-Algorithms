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

// Solution 1
void solve(Node *root, int k, int node,int& ans,vector<int> vec){
    if(root==NULL){
        return;
    }
    
    vec.push_back(root->data);
    
    solve(root->left,k,node,ans,vec);
    solve(root->right,k,node,ans,vec);
    
    if(root->data==node){
        for(int i=vec.size()-1;i>=0;i--){
            if(k==0){
                ans=vec[i];
                break;
            }
            k--;
        }
    }
    vec.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    if(root==NULL){
        return -1;
    }
    
    int ans=-1;
    vector<int> vec;
    
    solve(root,k,node,ans,vec);
    
    return ans;
}

// Solution 2

