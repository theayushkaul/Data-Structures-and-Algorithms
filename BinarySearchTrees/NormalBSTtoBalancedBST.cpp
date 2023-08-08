#include<bits/stdc++.h>
using namespace std;

// Given is the BST we have to form a balanced BST.
// Step 1: Store the inorder traversal of BST since it is a sorted Array
// mid of the array is root and all the elements to the left are a part of left subtree and to the right are a part of right subtree

template <typename T>
class TreeNode
{
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
};

void inorder(TreeNode<int>* root,vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* inorderToBST(int s,int e,vector<int> in){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderval;
    inorder(root,inorderval);
    
    return inorderToBST(0,inorderval.size()-1,inorderval);
}

int main(){

    return 0;
}