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

// Top View

vector<int> topView(Node *root)
    {
        map<int,int> nodes;
        queue<pair<Node*,int>>q;
        vector <int> ans;
        
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        
        while(!q.empty()){
           
           pair<Node*,int> temp = q.front();
           Node* frontNode = temp.first;
           q.pop();

           int horizontalDistance = temp.second;
           
           if(nodes.find(horizontalDistance)==nodes.end()){
               nodes[horizontalDistance]=frontNode->data;
           }
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,horizontalDistance-1));
           }
           
           if(frontNode->right){
               q.push(make_pair(frontNode->right,horizontalDistance+1));
           }
        }
        
        for(auto i:nodes){
                ans.push_back(i.second);
        }
        return ans;
    }

// Bottom View
vector <int> bottomView(Node *root) {
        map<int,int> nodes;
        queue<pair<Node*,int>>q;
        vector <int> ans;
        
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        
        while(!q.empty()){
           
           pair<Node*,int> temp = q.front();
           Node* frontNode = temp.first;
           q.pop();

           int horizontalDistance = temp.second;
           
           nodes[horizontalDistance]=frontNode->data;
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,horizontalDistance-1));
           }
           
           if(frontNode->right){
               q.push(make_pair(frontNode->right,horizontalDistance+1));
           }
        }
        
        for(auto i:nodes){
                ans.push_back(i.second);
        }
        return ans;
}

// In top view and bottom view there is only one difference: We need the first element at every horizontal distance and in bottom view we need the last one to occur

// Left View

void getLeftView(Node* root,vector<int>& ans, int lvl){
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    
    getLeftView(root->left,ans,lvl+1);
    getLeftView(root->right,ans,lvl+1);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   
   if(root==NULL){
       return ans;
   }
   
   getLeftView(root,ans,0);
   
   return ans;
}

// Right View

void getRightView(Node* root,vector<int>& ans, int lvl){
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    getRightView(root->right,ans,lvl+1);
    getRightView(root->left,ans,lvl+1);
    
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
   
    getRightView(root,ans,0);
    return ans;
}

// Difference between the code of right and left view
// For each level we started from l to r in left view and r to l in right view.
