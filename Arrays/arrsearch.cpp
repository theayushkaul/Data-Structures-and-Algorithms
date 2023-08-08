#include <bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int n, int key)
{
    sort(arr, arr + n);
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    return -1;
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << binSearch(a, 9, 8) << endl;
    return 0;
}