#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }

    int open = 0, close = 0;

    stack<char> st;
    for (auto i : str)
    {
        if (i == '{')
        {
            st.push(i);
            open++;
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
                open--;
            }
            else
            {
                close++;
            }
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main()
{

    return 0;
}