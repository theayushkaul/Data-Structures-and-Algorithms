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

Node* kReverse(Node* head, int k) {
       if(head==NULL){
           return NULL;
       }
    Node* curr=head;
    Node* next=NULL;
    Node* prev=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    head->next=kReverse(next,k);  
    return prev;
    
}