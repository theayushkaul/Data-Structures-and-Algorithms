#include<bits/stdc++.h>
using namespace std;

class Queue{

    int *arr;
    int size;

    public:
    int front,rear;
    Queue(int s){
        size=s;
        arr=new int[size];
        front=0;
        rear=0;
    }
    void push(int data){
        if(rear==size-1){
            return;
        }
        arr[rear++]=data;
    }

    int pop(){
        if(rear==front){
            return -1;
        }
        int ans=arr[front++];
        if(front==rear){
            front=0;
            rear=0;
        }
        return ans;
    }

    bool isEmpty(){
        if(rear==front){
            return true;
        }
        return false;
    }
};

int main(){

    return 0;
}