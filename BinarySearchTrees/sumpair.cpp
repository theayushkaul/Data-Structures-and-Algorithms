#include<bits/stdc++.h>
using namespace std;
template<class T> 
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode<int>* root,vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> in;
    inorder(root,in);
    int i=0,j=in.size()-1;
    while(i<j){
        if((in[i]+in[j])==target){
            return 1;
        }
        else if((in[i]+in[j])>target){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}

int main(){

    return 0;
}