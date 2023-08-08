// Stack Implementation-Array (By Class)

#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int top=-1;
    int size;
    public:
    Stack(int s){
        size=s;
        arr=new int[size];
    }
    void push(int data){
        if(size-top>1){
            arr[++top]=data;
            return;
        }
        cout<<"Stack Overflow"<<endl;
    }
    int peek(){
        if(top>=0 &&top<size)
            return arr[top];
        else
            cout<<"Stack is Empty"<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    bool isEmpty(){
        if(top==-1){
            return 1;
        }
        return 0;
    }
};

int main(){

    return 0;
}