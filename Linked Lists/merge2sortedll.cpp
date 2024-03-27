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

Node* solve(Node* first, Node* second){
//     If only one element is present in first
    
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    
    
    
//     Now we know that first ll has the smaller head
    Node* curr1=first;
    Node* curr2=second;
    Node* next1=curr1->next;
    Node* next2=curr2->next;
    
    
    while(next1!=NULL && curr2!=NULL){
        if( (curr1->data<=curr2->data) && (next1->data>=curr2->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=curr1->next;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;           
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second)
{
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    
    if(first->data<=second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
}

Node* mergell(Node* first, Node* second) {
        if (!first) return second;
        if (!second) return first;
        
        if (first->data < second->data) {
            first->next = mergell(first->next, second);
            return first;
        } else {
            second->next = mergell(first, second->next);
            return second;
        }
    }