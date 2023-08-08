#include <bits/stdc++.h>
using namespace std;

int pivotArr(int arr[], int n)
{
    // Index of Min Value in the array
    int s = 0, e = n - 1;

    while (s < e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}
int main()
{
    int a[] = {8,9,20,78,3,4};
    cout<<pivotArr(a,6)<<endl;
    return 0;
}