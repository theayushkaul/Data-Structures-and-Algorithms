#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public :
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Call the recursive helper function with initial range constraints
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBSTHelper(TreeNode* root, long long mini, long long maxi) {
        // Base case: If the node is NULL, it's a valid BST
        if (root == nullptr) {
            return true;
        }

        // Check if the current node's value is within the valid range
        if (root->val <= mini || root->val >= maxi) {
            return false;
        }

        // Recursively check the left and right subtrees
        // Update the range constraints accordingly
        return isValidBSTHelper(root->left, mini, root->val) &&
               isValidBSTHelper(root->right, root->val, maxi);
    }
};

int main(){

    return 0;
}