#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// Longest path ka sum 
// pair of length and sum till the leaf node is taken and at the end is compared to the max length 

void sumLongest(Node *root, pair<int,int>& ans,pair<int,int> p){
        
        if(root==NULL){
            if(ans.first<p.first){
                ans=p;
            }
            else if(ans.first==p.first){
                ans.second=max(ans.second,p.second);
            }
            return;
        }
        
        p.first++;
        p.second+=root->data;
        
        sumLongest(root->left,ans,p);
        sumLongest(root->right,ans,p);
        
        p.first--;
        p.second-=root->data;
    }
int sumOfLongRootToLeafPath(Node *root)
    {
        if(root==NULL){
            return -1;
        }
        
        pair<int,int> ans(0,0);
        sumLongest(root,ans,make_pair(0,0));
        
        return ans.second;
    }