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
Node * uniqueSortedList(Node * &head) {
    if(head==NULL){
        return NULL;
    }
    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            Node* dup=curr->next;
            curr->next=dup->next;
            dup->next=NULL;
            delete dup;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}