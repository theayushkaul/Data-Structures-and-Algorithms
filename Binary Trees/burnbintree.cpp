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

Node* createParentMapping(map<Node*,Node*>& mapping,Node* root,int target){
    Node* targetNode;
        
    queue<Node*> q;
    q.push(root);
    mapping[root]=NULL;
        
    while(!q.empty()){
    Node* frontNode=q.front();
            q.pop();
        
        if(frontNode->data==target){
            targetNode=frontNode;
        }
        if(frontNode->left){
            mapping[frontNode->left]=frontNode;
            q.push(frontNode->left);
        }
        
        if(frontNode->right){
            mapping[frontNode->right]=frontNode;
            q.push(frontNode->right);
        }
    }
    return targetNode;
}  

// Passing the targetNode as the starting Node and a mapping of the node to its parent Node
int burnTree(Node* root, map<Node*,Node*> nodeToparent){
    
    // time to store the ans
    int time=0;

    // Visited to store if the node is already burned or not
    map<Node*,bool> visited;

    // Level order Traversal
    queue<Node*> q;

    // First element in the queue is the targetnode
    q.push(root);
    
    // Since target is burnt first it is marked true
    visited[root]=1;
        
    while(!q.empty()){
        
        int size=q.size();

        // To store if anything is burnt in this traversal or not
        bool flag =0;

        // Burning the neighbouring nodes of the already burnt nodes *(If they are not already burnt i.e visited)*
        // The nodes present in the queue are burning so their neighbouring nodes would burn in this iteration. 
        // For each iteration in the following loop neighbouring nodes of each node would be burnt *(If not burnt already) 
        for(int i=0;i<size;i++){
            // Processing for the neighbouring nodes
            Node* front=q.front();
            q.pop();
            
            // Watching if the leftchild is present and burnt
            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }

            // Watching if the rightchild is present and burnt
            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }

            // Watching if the parentNode is present and burnt
            if(!visited[nodeToparent[front]] && nodeToparent[front]){
                flag=1;
                q.push(nodeToparent[front]);
                visited[nodeToparent[front]]=1;
        }
        }

        // If flag==1, the nodes are burnt successfully and it takes 1 second to burn all the neighbouring nodes
        if(flag==1){
            time++;
        }   
    }
    // Return the time taken to burn the tree 
    return time;
}

int minTime(Node* root, int target) 
{
    // Step1: Create a nodetoparent mapping
    map<Node*,Node*> nodeToparent;
    
    // Step2: Find the target Node and update the mapping
    Node* targetNode=createParentMapping(nodeToparent,root,target);
    
    // Step3: Burn the tree in min possible time
    return burnTree(targetNode,nodeToparent);
}