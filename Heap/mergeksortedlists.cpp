#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

class compare{
    public:
        bool operator()(Node<int>* a, Node<int>* b){
            return a->data > b->data;
        }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Base Case
    if(!listArray.size()){
        return NULL;
    }
    
    // Minheap
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minheap;

    // head and tail of the ans ll
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    
    // Initializing the minheap
    for(int i=0;i<listArray.size();i++){
        if(listArray[i]){
            minheap.push(listArray[i]);
        }
    }
    
    while(!minheap.empty()){
        Node<int>* node = minheap.top();
        minheap.pop();
        
        // Updating the minheap
        if(node->next){
            minheap.push(node->next);
        }
        
        // Updating the answer list
        if(!head){
            head=node;
            tail=node;
        }
        else{
            tail->next = node;
            tail=node;
        }
        
    }
    return head;
}

int main(){

    return 0;
}