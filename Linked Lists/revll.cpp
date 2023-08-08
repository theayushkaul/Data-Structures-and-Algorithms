#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node();
};

void printLL(Node* &Head){
    Node* temp=Head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reversell(Node* &head){
    if(head==NULL || head->next==NULL){
        cout<<head->data<<endl;
    }
    Node* curr=head;
    Node* prev =NULL;
    Node* forward=NULL;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
    printLL(head);
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    return 0;
}