//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
    int nodeCount(struct Node* tree){
        if(tree == NULL){
            return 0;
        }
        
        int leftSize = nodeCount(tree->left);
        int rightSize = nodeCount(tree->right);
        
        return leftSize + rightSize + 1;
    }
    // Assuming that the tree is CBT
    // For Max order
    bool isordered(struct Node* tree){
        // Leaf Node
        if(!tree->left && !tree->right){
            return 1;
        }
        // Only Left Child present
        if(!tree->right && tree->left){
            return (tree->data > tree->left->data);
        }
        // 2 childs present
        else if(tree->right && tree->left){
            
            bool left = isordered(tree->left);
            bool right = isordered(tree->right);
            
            return (tree->data >tree->left->data) && (tree->data > tree->right->data) && (right) && (left);
        }

        // IF only right child is present it cannot be a CBT
        return 0;
    }
    // For being a complete binary tree the nodes in the binary tree should be filled level wise
    // For 0 based indexing
    bool isCBT(struct Node* root,int i,int nodeCnt){
        // Base Case
        if(root==NULL){
            return true;
        }
        // That this node doesn't exist
        if(i>=nodeCnt){
            return 0;
        }
        
        else{
            bool left = isCBT(root->left,2*i+1,nodeCnt);
            bool right = isCBT(root->right,2*i+2,nodeCnt);
            return left && right;
        }
    }

    public:
        bool isHeap(struct Node* tree) {
            return isCBT(tree,0,nodeCount(tree)) && isordered(tree);
        }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
