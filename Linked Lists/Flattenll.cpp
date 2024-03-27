#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    	int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 };
Node* mergell(Node* &first, Node* &second) {
        if (!first) return second;
        if (!second) return first;
        
        if (first->data < second->data) {
            first->child = mergell(first->child, second);
            return first;
        } else {
            second->child = mergell(first, second->child);
            return second;
        }
    }

Node* flattenLinkedList(Node* head) 
{
    if(head == NULL){
        return head;
    }

	Node* down = head;
    Node* right = flattenLinkedList(head->next);

    down->next = NULL;

	Node* ans = mergell(head, right);
    return ans;
}
int main(){

    return 0;
}
// https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM