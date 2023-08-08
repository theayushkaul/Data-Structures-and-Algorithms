// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // we create a heap to store k smallest elements
        priority_queue<int> pq;
        int count = 0;
        while(count<k && l<=r){
            pq.push(arr[l]);
            count++;
            l++;
        }
        
        while(l<=r){
            if(arr[l]<pq.top()){
                pq.pop();
                pq.push(arr[l]);
            }
            l++;
        }
        // The topmost element in the heap will be the kth smallest elements
        return pq.top();
    }
};
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
