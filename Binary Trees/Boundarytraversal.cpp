#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* buildTree(Node* root){
    
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter data for inserting in right of"<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void getLeafNodes(Node* root,vector<int>& result){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            result.push_back(root->data);
            return;
        }
        
        getLeafNodes(root->left,result);
        getLeafNodes(root->right,result);
    }

void getRightNodes(Node* root,vector<int>& result){
        if(root==NULL){
            return;
        }
        if(root->right==NULL && root->left==NULL){
            return;
        }
        if(root->right){
            getRightNodes(root->right,result);
        }
        else{
            getRightNodes(root->left,result);
        }
        
        result.push_back(root->data);
    }
void getLeftNodes(Node* root,vector<int>& result){
        if(root==NULL){
            return;
        }
        if(root->right==NULL && root->left==NULL){
            return;
        }
        
        result.push_back(root->data);
        
        if(root->left){
            getLeftNodes(root->left,result);
        }
        else{
            getLeftNodes(root->right,result);
        }
    }

vector<int> boundary(Node *root){
        vector<int> result;
        
        // If root is NULL
        if(root==NULL){
            return result;
        }
        
        result.push_back(root->data);
        
        // For the left part
        getLeftNodes(root->left,result);
        
        // For leaf Nodes
        if(root->left || root->right){
            getLeafNodes(root,result);
        }
        
        // For right part
        getRightNodes(root->right,result);
        
        return result;
}

int main(){

    Node* root=NULL;

    root=buildTree(root);
    return 0;
}