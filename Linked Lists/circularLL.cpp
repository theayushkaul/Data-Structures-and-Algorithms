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

void insertNode(Node* &tail, int d,int preval=0){
    if(tail==NULL){
        Node* temp=new Node(d);
        temp->next=temp;
        tail=temp;
        cout<<"Value Inserted: "<<temp->data<<" "<<temp->next->data<<endl;

    }
    else{
        Node* temp=new Node(d);
        Node* prev=tail;
        while(prev->data!=preval){
            prev=prev->next;
        }
        temp->next=prev->next;
        prev->next=temp;
        cout<<"Value Inserted: "<<temp->data<<" "<<temp->next->data<<endl;
    }
}

void printLL(Node* &tail){

    if(tail==NULL){
        cout<<"Linked List is Empty"<<endl;
    }

    Node* temp=tail->next;
    while(temp!=tail){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<tail->data<<" ";
    cout<<endl;
}

void deleteNode(Node* &tail,int value){
    Node* curr=tail->next;
    Node* prev=tail;
    // If NULL Node
    if(tail==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    // If 1 node is present
    if(tail->next==tail){
        tail=NULL;
        return;
    }


    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }

    if(tail==curr){
        tail=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}

int main(){

    Node* tail=NULL;

    insertNode(tail,12);
    insertNode(tail,120,12);
    insertNode(tail,14,12);
    printLL(tail);
    deleteNode(tail,12);
    printLL(tail);


    return 0;
}
