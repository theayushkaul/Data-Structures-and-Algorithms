#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }   
};

// Approach 1
// Step 1: merge the inorder of both the BST and sort to get the inorder of the Final BST
// Step 2: Get BST from the inorder traversal

void inorder(TreeNode *root,vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode *inorderToBst(vector<int> in,int s,int e){
    
    if(s>e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    TreeNode *root= new TreeNode(in[mid]);
    
    root->left = inorderToBst(in,s,mid-1);
    root->right = inorderToBst(in,mid+1,e);
    
    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
    vector<int> inordert;

    inorder(root1,inordert);
    inorder(root2,inordert);
    
    sort(inordert.begin(),inordert.end());

    return inorderToBst(inordert,0,inordert.size()-1);    
}

// Approach 2
// 
void convertIntoSortedDLL(TreeNode* root,TreeNode* &head){
    
    if(root == NULL){
        return;
    }
    
    convertIntoSortedDLL(root->right,head);
    
    root->right = head;
    if(head!= NULL){
        head->left = root;
    }
    
    head = root;
    
    convertIntoSortedDLL(root->left,head);
}

// Step 2: Merge Two linked List

TreeNode * mergeLinkedList(TreeNode *head1, TreeNode *head2){
    TreeNode* head = NULL;
    TreeNode* tail = NULL;
    
    while(head1 !=NULL && head2 !=NULL){
        if(head1->data < head->data){
            if(head==NULL){
                head = head1;
            }
            else{
                tail->right = head1;
                head1->left = tail;
            }
            tail = head1;
            head1=head1->right;
        }
        else{
            if(head == NULL){
                head = head2;
            }
            else{
                tail->right = head2;
                head2->left = tail;
            }
            tail = head2;
            head2=head2->right;
        }
    }
    while(head1){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1=head1->right;
    }
    while(head2){
        tail->right = head2;
        head1->left = tail;
        tail = head2;
        head2=head2->right;
    }
    
    return head;
}

// Step 3: Create a Balanced BST through sorted linked list
int getLength(TreeNode* head){
    int cnt=0;
    TreeNode* temp = head;
    while(temp){
        temp=temp->right;
        cnt++;
    }
    return cnt;
}
// Not working
TreeNode * sortedLLtoBST(TreeNode* &head,int n){
    if(n<=0 || head == NULL ){
        return NULL;
    }
    
    TreeNode* left = sortedLLtoBST(head,n/2);
    TreeNode* root = head;
    root->left = left;
    head=head->right;
    root->right = sortedLLtoBST(head,n/2-1);
    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
    
    TreeNode *head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;
    
    TreeNode *head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    TreeNode *head = mergeLinkedList(head1,head2);
    return sortedLLtoBST(head,getLength(head));
}

int main(){

    return 0;
}