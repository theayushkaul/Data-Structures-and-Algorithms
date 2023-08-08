#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
};

// Additional class to store 4 information 
class info{
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
};

info solve(TreeNode<int>* root,int &ans){

    if(root==NULL){
        info ans;
        ans.mini = INT_MAX;
        ans.maxi = INT_MIN;
        ans.isBST = 1;
        ans.size = 0;
        return ans;
    }
    // Recursive call for the left subtree and right subtree
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);
    
    // Taliking about current node
    info curr;

    // Size of the BT till curr Node
    curr.size = left.size + right.size + 1;

    // Boolean isBST to know that the BT is a BST
    curr.isBST = (left.isBST) && (right.isBST) && (left.maxi<root->data) && (root->data < right.mini);
    
    // If till curr is a BST update the ans
    if(curr.isBST){
        ans=max(ans,curr.size);
    }

    // Updating the minimum and maximum in the BST: Since the minimum in a BST is always in the left subtree and maximum is in the right subtree 
    curr.mini = min(root->data,left.mini);
    curr.maxi = max(root->data,right.maxi);
    
    return curr;
   
}

int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;
}

int main(){

    return 0;
}