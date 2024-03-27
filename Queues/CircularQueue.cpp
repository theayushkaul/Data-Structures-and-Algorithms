#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    int front,rear;
    int size;
    int* arr;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size=n;
        front=-1;
        rear=-1;
        arr=new int[size];
    }

    bool enqueue(int value){
        if(rear==(front-1)%(size-1) || (rear==size-1 && front==0)){
            return false;
        }
        else if(front==-1){
            front=0;
            rear=0;
        }
        else if(front>0 && rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    int dequeue(){
        if(front==-1){
            return -1;
        }
        int ans;
        if(front==size-1){
            ans=arr[front];
            front=0;
        }
        else if(front==rear){
            ans=arr[front];
            front=-1;
            rear=-1;
        }
        else{
            ans=arr[front++];
        }
        return ans;
    }
};

int main(){

    return 0;
}