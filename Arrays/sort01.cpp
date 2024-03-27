// Using Two Pointers
#include<bits/stdc++.h>
using namespace std;
void sortZeroesAndOne(int arr[], int size)
{
    int i = 0, e = size - 1;
    while(i<e){
        if(arr[i] == 1 && arr[e] == 0){
            swap(arr[i++],arr[e--]);
        }
        while(arr[i] == 0){
            i++;
        }
        while(arr[e] == 1){
            e--;
        }
    }
}
int main(){

    return 0;
}