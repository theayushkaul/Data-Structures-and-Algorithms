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

int getLength(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL && temp->data!=-1){
        count++;
        temp=temp->next;
    }
    return count;
}
Node *findMiddle(Node *head) {
    Node* temp=head;
    int mid=(getLength(head)/2);
    int count=0;
    while(count<mid){
        temp=temp->next;
        count++;
        }
    return temp;
}

// Approach 2
Node *findMiddle(Node *head) {
    if(head->next==NULL || head==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL){
        if(fast->next!=NULL)
            fast=fast->next->next;
        else{
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}