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
Node* insertintoBST(Node* &root,int data){
    if(root==NULL){
        Node* root=new Node(data);
        return root;
    }
    if(data > root->data){
        root->right=insertintoBST(root->right,data);
    }
    else{
        root->left=insertintoBST(root->left,data);
    }
    return root;
}
Node* minValueNode(Node* node)
{
    Node* temp = node;
    while (temp && temp->left != NULL){    
        temp = temp->left;
    }
    return temp;
}
Node* maxValueNode(Node* node)
{
    Node* temp = node;
    while (temp && temp->right != NULL)
        temp = temp->right;
    return temp;
}
Node* deleteNode(Node* root, int data)
{
    if (root == NULL){
        return root;
    }
    if (data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left==NULL and root->right==NULL){
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertintoBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            cout << endl;
            if(!q.empty()) { 
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }
            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}
void inorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}
int main(){
    
    Node* root=NULL;
    takeInput(root);
    
    cout<<"Level-Order Traversal"<<endl;
    levelOrderTraversal(root);
    
    cout<<"InOrder Traversal: ";
    inorder(root);
    cout<<endl;
    
    cout<<"PostOrder Traversal: ";
    postorder(root);
    cout<<endl;
    
    deleteNode(root,1);
    
    cout<<"PreOrder Traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Minimum Value in the binary tree is: "<<minValueNode(root)->data<<endl;
    cout<<"Maximum Value in the binary tree is: "<<maxValueNode(root)->data<<endl;
    
    return 0;
}
// 10 18 1 11 9 45 8 -1