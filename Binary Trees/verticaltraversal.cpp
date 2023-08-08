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


// Vertical Traversal
vector<int> verticalOrder(Node *root)
    {
        // A map to store horizontal distance and another map of level to the vector of elements.
        // map<hd,map<lvl,vector<int>>>

        map< int , map< int,vector<int> > > nodes;

        // A queue to store a pair of node and a pair of horizontal distance(hd) from root and level(lvl)
        // queue<pair<Node*,pair<hd,lvl>>>

        queue<pair<Node*,pair<int,int>>> q;
        vector <int> ans;
        
        if(root==NULL){
            return ans;
        }
        
        // Since the root element is at 0th level and is also a refrenece point.
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
           
           pair<Node*,pair<int,int>> temp = q.front();
           Node* frontNode = temp.first;
           q.pop();

           int horizontalDistance = temp.second.first;
           int lvl = temp.second.second;
           
           nodes[horizontalDistance][lvl].push_back(frontNode->data);
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,make_pair(horizontalDistance-1,lvl+1)));
           }
           
           if(frontNode->right){
               q.push(make_pair(frontNode->right,make_pair(horizontalDistance+1,lvl+1)));
           }
        
        }
        
        for(auto i: nodes){
            // i: A row representing <hd,map>
            
            for(auto j : i.second){
                // A map of int and a vector
               
                for(auto k: j.second){
                    // k is representing the vector
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }