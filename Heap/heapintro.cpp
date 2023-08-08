#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
        heap(){
            size=0;
            arr[0]=-1;
        }
        void insert(int val){
            size++;
            int index =size;
            arr[index]= val;

            while(index>1){
                int parent = index/2;

                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void deleteNode(){
            arr[1]=arr[size];
            size--;
            
            int i=1;
            while(i<size){

                int leftIndex=2*i;
                int rightIndex=2*i+1;

                if(leftIndex<size && arr[i]<arr[leftIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i=leftIndex;
                }
                else if(rightIndex<size && arr[i]<arr[rightIndex]){
                    swap(arr[i],arr[rightIndex]);
                    i=rightIndex;
                }
                else{
                    return;
                }
            }
        }
};

// heapify using recursion
// heapify algorithm is used to convert an array into a heap
// Here we are using max heap

// 1-based Indexing
void heapify(int arr[],int n,int i){

    // heap starts from 1 not 0;
    // Root node is at first index

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    // Checks the left child
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    // checks the right child
    if(left<=n && arr[largest]<arr[right]){
        largest=right;
    }
    
    // checks if either left child or right child is greater than the root node
    if(largest!=i){
        // if it is then the nodes are swapped
        swap(arr[largest],arr[i]);
        // And heapify that subtree(left or right)
        heapify(arr,n,largest);
    }

}

void heapSort(int arr[],int n){

    int size=n;

    while(size > 1){

        // step 1
        swap(arr[size],arr[1]);

        // step 2
        size--;
        
        // step 3
        heapify(arr,size,1);
    
    }
}

int main(){
    heap h;
    
    // Inseriton in the heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    // Deletion in the heap
    h.deleteNode();
    h.print();

    int arr[8]={-1,12,54,55,67,8,29,11};
    int n=7;
    //Since (n/2+1) indexes have only leaf nodes. 
    for (int i = n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }

    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"Heap Sort: ";
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}