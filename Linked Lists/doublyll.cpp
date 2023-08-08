#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        // Constructor (Optional)
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
        ~Node(){ 
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
                this->prev=NULL;
            }
        }
};

void printLL(Node* &head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

void insertAthead(Node* &head,int data){

    Node* nnode =new Node(data);
    nnode->next=head;
    head->prev=nnode;
    head=nnode;
}

void insertAttail(Node* &tail,int data){

    Node* nnode=new Node(data);
    nnode->prev=tail;
    tail->next=nnode;
    tail=nnode;
}

void insertAtposition(Node* &tail,Node* &head,int position,int data){
    
    if(position==1){
        insertAthead(head,data);
        return;
    }

    if(position == getLength(head)+1){
        insertAttail(tail,data);
        return;
    }

    Node* curr=head;
    int count=1;

    while(count<position-1){
        curr=curr->next;
        count++;
    }

    Node* temp=new Node(data);

    temp->next=curr->next;
    curr->next->prev=temp;
    curr->next=temp;
    temp->prev=curr;

}

void deleteNode(Node* &head,Node* &tail,int position){

    // If position is head;
    if(position==1){
        Node* curr = head;

        head=curr->next;
        curr->next->prev=NULL;
        curr->next=NULL;
        
        delete curr;
        return;
    }

    if(position==getLength(head)){
        Node* curr = tail;

        tail=curr->prev;
        curr->prev->next=NULL;
        curr->prev=NULL;
        
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

    curr->prev=NULL;
    prev->next=curr->next;
    curr->next->prev=prev;
    curr->next=NULL;

    delete curr;

}

int main(){

    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    insertAthead(head,200);
    insertAthead(head,40);
    insertAttail(tail,50);
    insertAtposition(tail,head,2,54);
    printLL(head);
    cout<<getLength(head)<<endl;

    deleteNode(head,tail,5);
    printLL(head);

    cout<<"Head is: "<<head->data<<" Tail is: "<<tail->data<<endl;
    return 0;
}