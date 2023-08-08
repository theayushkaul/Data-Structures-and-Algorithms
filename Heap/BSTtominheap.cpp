#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            data=val;
            left=NULL;
            right=NULL;
        }

};

TreeNode* insertintoBST(TreeNode* &root,int data){
    if(root==NULL){
        TreeNode* root=new TreeNode(data);
        return root;
    }
    if(data > root->data){
        root->right=insertintoBST(root->right,data);
    }
    else{
        root->left=insertintoBST(root->left,data);
    }
    return root;
}

void takeInput(TreeNode* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertintoBST(root,data);
        cin>>data;
    }
}

void inorder(TreeNode* root){

    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// To convert a BST into a min heap and under 2 condition:
// Given BST is a CBT always
// The values in left subtree should always be less than right subtree

void inorder(TreeNode* root,vector<int>& in){

    if(root==NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

// The tree should be populated using inorder traversal in preorder format to get the desired min heap
// The first (i-1) element will always be lesser than the ith element . First element will be the root
void preorderFill(TreeNode* &root,vector<int> in,int& i){
    if(root==NULL || i>=in.size()){
        return;
    }
    
    root->data = in[i++];
    preorderFill(root->left,in,i);
    preorderFill(root->right,in,i); 
}

int main(){
    // To make a BST
    TreeNode* root=NULL;
    takeInput(root);

    // To convert a BST to min heap
    vector<int> in;
    inorder(root,in);

    cout<<"Inorder of the BST"<<endl;
    inorder(root);

    // Populating the tree
    int i=0;
    preorderFill(root,in,i);

    cout<<"Inorder of the Heap"<<endl;
    inorder(root);

    return 0;
}
// 4 2 6 1 3 5 7 -1