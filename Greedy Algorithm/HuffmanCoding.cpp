#include<bits/stdc++.h>
using namespace std;

// A treenode class
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
        
};
// Used to compare two tree nodes
class cmp{
    public:
    bool operator()(TreeNode* a, TreeNode* b){
        return a->data > b->data;
    }
};
class Solution
{
    // Traverse Function: It will perform preOrder traversal on Huffman tree
    // The alphabets or the frequency of the alphabets is at the leaf node
    // So we will traverse till the leaf node and get the huffmann code 
    // Left: 0 and right: 1
    void traverse(TreeNode* root, string temp, vector<string>& ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
            return;
        }
        
        traverse(root->left,temp+'0',ans);
        traverse(root->right,temp+'1',ans);
        
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int n)
		{
            // Build a priority queue to get 2 min nodes everytime and make a huffman tree
		    priority_queue<TreeNode*, vector<TreeNode*>,cmp> pq;
        
            for(int i=0;i<= n-1;i++){
                TreeNode* temp = new TreeNode(f[i]);
                pq.push(temp);
            }
            
            int cost = 0;
            
            while(pq.size() > 1){
                TreeNode* left = pq.top();
                pq.pop();
                TreeNode* right = pq.top();
                pq.pop();
                
                TreeNode* root = new TreeNode(left->data + right->data);
                root->left = left;
                root->right = right;
                
                pq.push(root);
            }
            
            TreeNode* root = pq.top();
		    vector<string> ans;
		    string temp = "";
		    
		    traverse(root,temp,ans);
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends