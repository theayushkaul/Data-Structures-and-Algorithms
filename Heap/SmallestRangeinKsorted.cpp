#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        int row;
        int col;

        Node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {

    priority_queue<Node*,vector<Node*>,compare> minHeap;
    int maxi = INT_MIN, mini = INT_MAX;

    // pushing the minimum of k arrays in the heap
    for(int i=0;i<k;i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new Node(element,i,0));
    }

    int start = mini,end = maxi;
    
    // Process Range
    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // Range Updation
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }
        // If next element exists
        if(temp->col + 1 < n){
            maxi = max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col+1));
        }else{
            // Next element doesn't exist
            break;
        }
    }

    return end - start + 1;
}