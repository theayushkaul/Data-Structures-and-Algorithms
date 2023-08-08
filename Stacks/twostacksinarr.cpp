#include <bits/stdc++.h> 
class TwoStack {
    int *stack1;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        size=s;
        stack1=new int[s];
        top1=-1;
        top2=s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2-top1>1){
            stack1[++top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2-top1>1){
            stack1[--top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1==-1){
            return -1;
        }
        return stack1[top1--];
        
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2==size){
            return-1;
        }
        return stack1[top2++];
    }
};