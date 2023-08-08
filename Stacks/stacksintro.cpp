#include<bits/stdc++.h>
using namespace std;

int main(){

    // STL Stack Implementation
    stack<int> s;

    // pushing
    s.push(2); 
    s.push(5); 
    s.push(4); 
    s.push(3); 
    s.push(1); 

    // peek
    cout<<s.top()<<endl;

    // isEmpty
    cout<<s.empty()<<endl;

    // pop
    s.pop();
    cout<<s.top()<<endl;

    // size
    cout<<"Size  of the stack is: "<<s.size()<<endl;
    return 0;
}