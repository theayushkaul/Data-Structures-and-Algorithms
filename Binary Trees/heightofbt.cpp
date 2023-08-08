#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Height of a Binary Tree
int height(struct Node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }

    int left = height(Node->left);
    int right = height(Node->right);

    int ans = max(left, right) + 1;

    return ans;
}

// Diameter of a binary tree - in O(n) T.C
// Pair<diameter,height>
pair<int, int> fastDiameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans = make_pair(max(op1, max(op2, op3)), max(left.second, right.second) + 1);

    return ans;
}

int diameter(Node *root)
{
    return fastDiameter(root).first;
}

/*
    isBalanced function in O(n)-TC

    A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

    Three Conditions:
    1) Left Subtree is balanced
    2) Right Subtree is Balanced
    3) abs(height(Right subtree)- height(left Subtree)) <= 1
*/

pair<bool, int> balanced(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(1, 0);
        return p;
    }

    pair<bool, int> left = balanced(root->left);
    pair<bool, int> right = balanced(root->right);

    bool condition = abs(left.second - right.second) <= 1;

    pair<bool, int> ans = make_pair((right.first && left.first && condition), (max(left.second, right.second) + 1));
    return ans;
}

bool isBalanced(Node *root)
{
    return balanced(root).first;
}
