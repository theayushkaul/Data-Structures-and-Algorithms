#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        // Constructor (Optional)
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~Node(){ 
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
        }
};

void insertAthead(Node* &Head, int d){

    // Create a new node
    Node* temp=new Node(d);
    temp->next=Head;
    Head=temp;

}

void printLL(Node* &Head){

    // Because I don't wnat to change anything about head
    Node* temp=Head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAttail(Node* &tail,int d){

    // Create a new node
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertatPostion(Node* &head,int position,int d, Node* &tail){

    // Inserting the element at Start
    if(position == 1){
        insertAthead(head,d);
        return;
    }

    Node* temp= head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
        }
    

    // Inserting the element at last postion
    if(temp->next==NULL){
        insertAttail(tail,d);
        return;
    }

    Node* newnode = new Node(d);
    newnode->next=temp->next;
    temp->next=newnode;
}

void deleteNode(Node* &head,Node* &tail,int position){

    // If position is head;
    if(position==1){
        Node* curr = head;
        head=curr->next;
        curr->next=NULL;
        delete curr;
        return;
    }
    
    int cnt=1;
    Node* prev= NULL;
    Node* curr=head;
    
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }

    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

    if(prev->next==NULL){
        tail=prev;
    }
}

int main(){

    Node* node1 = new Node(10);

    Node* head=node1;
    Node* tail=node1;

    printLL(head);

    insertAthead(head,12);
    insertAttail(tail,15);
    insertAttail(tail,200);

    insertatPostion(head,3,600,tail);

    printLL(head);

    // deleteNode(head,tail,5);
    // printLL(head);

    cout<<tail->data<<" "<<head->data<<endl;
    return 0;
}