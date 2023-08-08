// LINK to Q =>  https://leetcode.com/problems/string-compression/
#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    // using i to store last consecutive occurence in the chars vector;
    // using s to store first occurence in the chars vector; 
    int i = 0, s = 0, n = chars.size();
    while (i < n)
    {
        int j = i + 1;

        // COUNTING THE NUMBER OF OCCURENCES OF CHAR[I];
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        // STORING THE CHAR[I] VALUE IN CHAR[S] : THE ALPHABET 
        chars[s++] = chars[i];

        // STORING THE COUNT OF ALPHABETS IN CHARS VECTOR : I.E => J-I
        if ((j - i) > 1)
        {
            string num = to_string(j - i);
            for (int k = 0; k < num.length(); k++)
            {
                chars[s++] = num[k];
            }
        }

        // UPDATING THE VALUE OF I =J : TO GET A NEW CHARACTER AT CHARS[I];
        i = j;
    }
    return s;
}