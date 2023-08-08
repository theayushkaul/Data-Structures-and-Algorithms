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

Node* sortList(Node *head){
    // For a Null linked list and single node ll , the ll is sorted
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* temp=head;

    int count[3]={0};
    while(temp!=NULL){
        count[temp->data]++;
        temp=temp->next;
    }

    int i=0;
    temp=head;
    while (temp!=NULL && i<3)
    {
        if(count[i]==0){
            i++;
        }
        temp->data=i;
        count[i]--;
        temp=temp->next;
    }
    
    return head;
}

// Second Approach: Not replacing data
// populate is function to insert at the tail
void populate(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}

Node* sortList(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);

    Node* zeroTail=zeroHead;
    Node* oneTail=oneHead;
    Node* twoTail=twoHead;

    Node* curr=head;
    while (curr!=NULL)
    {
        int val=curr->data;
        if(val==0){
            populate(zeroTail,curr);
        }
        else if(val==1){
            populate(oneTail,curr);
        }
        else if(val==2){
            populate(twoTail,curr);
        }
        curr=curr->next;
    }

    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
        oneTail->next=twoHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    twoTail->next=NULL;
    head=zeroHead->next;

    // Delete dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}