#include<bits/stdc++.h>
using namespace std;


template <typename T>

class BinaryTreeNode{
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    
    BinaryTreeNode<int>* temp=root;
    int pred=-1;
    int succ=-1;
    
//     Finding the key in BST
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
             temp=temp->right;
        }
    }
    
//     Pred
      BinaryTreeNode<int>* left=temp->left;
      if(left!=NULL){
            pred=left->data;
            left=left->right;
        }
//     Succ
    BinaryTreeNode<int>* right=temp->right;
    if(right!=NULL){
         succ=right->data;
         right=right->left;
    }
    
    return make_pair(pred,succ);
}