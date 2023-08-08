#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Pushing -1 because there is only positive integers in the array.
    stack<int> st;
    st.push(-1);

    for(int i=arr.size()-1;i>=0;i--){
        
        int n=arr[i];
        // If the topmost element in the stack is less than the current number store this number
        if(st.top()<arr[i]){
            arr[i]=st.top();
        }
        // If the topmost element isn't lesser than the current element then pop till we get a lesser element.
        else{
            while(st.top()>=arr[i]){
                st.pop();
            }
            arr[i]=st.top();
        }
        // store the current element in the stack to compare it with coming integers
        st.push(n);
    }
    
    return arr;
}