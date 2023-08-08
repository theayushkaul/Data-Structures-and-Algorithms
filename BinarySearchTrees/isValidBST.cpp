#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public :
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val) {
            this -> val = val;
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

bool isValidBST(TreeNode* root) {
    if(root==NULL || root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left!=NULL && root->right!=NULL){
        if(root->val<root->right->val && root->val > root->left->val){
                return isValidBST(root->left) && isValidBST(root->right);
            }            
        }
    else if(root->left==NULL && root->right!=NULL){
        if(root->val<root->right->val){
                return isValidBST(root->right);
            } 
    }
    else if(root->left!=NULL && root->right==NULL){
        if(root->val>root->left->val){
                return isValidBST(root->left);
            } 
    }
    return 0;
}

int main(){

    return 0;
}