#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

node* buildTree(node* root){
    
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter data for inserting in right of"<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

// Zig-Zag Traversal
vector <int> zigZagTraversal(node* root)
    {
    	vector<int> result;
    	if(root == NULL)
    	    return result;
    	
    	queue<node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()) {
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //Level Process
    	    for(int i=0; i<size; i++) {
    	        
    	        node* frontNode = q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode -> left);
    	            
    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }
    	    
    	    //direction change karni h
    	    leftToRight = !leftToRight;
    	   
    	  for(auto i: ans) {
    	      result.push_back(i);
    	  }  
    	}
    	    return result;
    }

int main(){

    node* root=NULL;

    root=buildTree(root);
    return 0;
}