#include<bits/stdc++.h>
using namespace std;
queue<int> reverse(queue<int> &q)
{
    if(q.empty()){
        return q;
    }
    
    int n=q.front();
    q.pop();
    
    reverse(q);
    
    q.push(n);
    
    return q;
}

void printq(queue<int> q){

    int n=q.size();

    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
}

int main(){
    
    queue<int> myQueue;
    // Pushing elements in the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);

    myQueue.pop();
    cout<<myQueue.size()<<endl;
    
    printq(myQueue);

    reverse(myQueue);

    printq(myQueue);

    return 0;
}