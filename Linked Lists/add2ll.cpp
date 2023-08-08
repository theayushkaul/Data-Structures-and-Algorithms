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

void insertathead(Node* &head,int data){
        Node* temp=new Node(data);
        if(head==NULL){
            head=temp;
            return;
        }
        temp->next=head;
        head=temp;
}
    
    Node* reverse(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
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
        return head;
    }
    Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int sum=0,carry=0;
    // Reversing the ll to get the sum 
        Node* temp1 = reverse(first);
        Node* temp2 = reverse(second);
        
        Node* head=NULL;
        
        while(temp1!=NULL && temp2!=NULL){
            sum=temp1->data+temp2->data+carry;
            insertathead(head,sum%10);
            carry=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        // if length(temp1)>temp2 then temp1!=NULL
        while(temp1!=NULL){
            sum=temp1->data+carry;
            insertathead(head,sum%10);
            carry=sum/10;
            temp1=temp1->next;
        }
        // simmilarly
        while(temp2!=NULL){
            sum=temp2->data+carry;
            insertathead(head,sum%10);
            carry=sum/10;
            temp2=temp2->next;
        }
        // if carry is > 0 then there is one more digit to add in the ll 
        if(carry>0){
            insertathead(head,carry);
        }
        return head;
    }