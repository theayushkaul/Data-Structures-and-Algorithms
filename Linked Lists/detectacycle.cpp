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

bool detectLoop(Node* head){

    if(head==NULL){
        return false;
    }

    map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return 1;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

// Using Floyd's cycle detection method

Node* floydCycle(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* fast=head;
    Node* slow=head;
    while (fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        
        slow=slow->next;
        if(fast==slow){
            return fast;
        }
    }
    // if the loop ends,it means the ll has no loops i.e ends with NULL
    return NULL;
}

Node* startNode(Node* head){

    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=floydCycle(head);
    while (fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast==slow){
            break;
        }
    }
    
    return fast;
}

void remove(Node* head){
    Node* startnode=startNode(head);
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next==startnode){
            temp->next=NULL;
        }
        temp=temp->next;
    }
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    return 0;
}