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

// Using preorder and inorder
void createMap(int in[],int n,map<int,int>& mapping){
        for(int i=0;i<n;i++){
            mapping[in[i]]=i;
        }
    }
    Node* solve(int in[],int pre[],int &poIndex,int ioStart,int ioEnd,int n,map<int,int>& mapping){
        if(poIndex>=n || ioStart>ioEnd){
            return NULL;
        }
        
        int element=pre[poIndex++];
        Node* root=new Node(element);
        int pos=mapping[element];
        
        root->left=solve(in,pre,poIndex,ioStart,pos-1,n,mapping);
        root->right=solve(in,pre,poIndex,pos+1,ioEnd,n,mapping);
        
        return root;
}
Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        map<int,int> mapping;
        createMap(in,n,mapping);
        Node* ans= solve(in,pre,preOrderIndex,0,n-1,n,mapping);
        
        return ans;
    }

// Using Inorder and postorder 

void createMap(int in[],int n,map<int,int>& mapping){
        for(int i=0;i<n;i++){
            mapping[in[i]]=i;
        }
    }
Node* solve(int in[],int post[],int &poIndex,int ioStart,int ioEnd,int n,map<int,int>& mapping){
        if(poIndex<0 || ioStart>ioEnd){
            return NULL;
        }
        
        int element=post[poIndex--];
        Node* root=new Node(element);
        int pos=mapping[element];
        
        root->right=solve(in,post,poIndex,pos+1,ioEnd,n,mapping);
        root->left=solve(in,post,poIndex,ioStart,pos-1,n,mapping);
        
        
        return root;
}

Node *buildTree(int in[], int post[], int n) {
        int postOrderIndex=n-1;
        map<int,int> mapping;
        createMap(in,n,mapping);
        Node* ans= solve(in,post,postOrderIndex,0,n-1,n,mapping);
        return ans;
    
}