// Using Two pointers
#include<bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
  int j = 0, k = n-1;
   for (int i=0; i <= k; i++) {
       if (arr[i] == 0)
           swap(arr[i], arr[j++]);
       else if (arr[i] == 2)
           swap(arr[i--], arr[k--]);
   } 
}
int main(){

    return 0;
}