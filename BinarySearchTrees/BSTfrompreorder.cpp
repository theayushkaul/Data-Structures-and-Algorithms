#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
};

BinaryTreeNode* solve(vector<int>& preorder,int mini,int maxi,int &i){
    
    // Base Case: If the left child or right child goes out of their defined range i.e (mini,maxi) 
    if(i>=preorder.size() || preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    
    BinaryTreeNode* node = new BinaryTreeNode(preorder[i++]);
    node->left = solve(preorder,mini,node->data-1,i);
    node->right = solve(preorder,node->data+1,maxi,i);
    
    return node;
}
BinaryTreeNode* preorderToBST(vector<int> &preorder) {
    int mini=INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder,mini,maxi,i);
}

int main(){

    return 0;
}