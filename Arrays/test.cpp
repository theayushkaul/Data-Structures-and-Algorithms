#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Brute way
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (arr[i] + arr[j] > K)
            {
                break;
            }
            for (int t = j + 1; t < n; t++)
            {
                if (arr[i] + arr[j] + arr[t] == K)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[t]);
                    if (std::find(ans.begin(), ans.end(), temp) == ans.end())
                    {
                        ans.push_back(temp);
                    }
                    break;
                }
            }
        }
    }
    return ans;
}
// Optimized way
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    vector<vector<int>> v;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {

        // to remove duplicates within the loop , hence decreasing the overall time taken
        if (i == 0 || i > 0 && (arr[i] != arr[i - 1])) 
        {
            int low = i + 1;
            int high = n - 1;
            
            while (low < high)
            {
                if (arr[low] + arr[high] + arr[i] == K)
                {
                    vector<int> temp;
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    temp.push_back(arr[i]);
                    v.push_back(temp);

                    while (low < high && arr[low] == arr[low + 1]) // removing duplicates from start
                        low++;
                    
                    while (low < high && arr[high] == arr[high - 1]) // removing duplicates from end
                        high--;

                    low++;
                    high--;
                }
                
                else if (arr[low] + arr[high] + arr[i] < K)
                    low++;
                
                else
                    high--;
            }
        }
    }
    return v;
}