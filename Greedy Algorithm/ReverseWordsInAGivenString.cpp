//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> str;
        string temp = "";
        
        for(int i = 0; i<S.length();i++){
            if(S[i] != '.'){
                temp += S[i];
            }else{
                str.push_back(temp);
                temp = "";
            }
        }
        str.push_back(temp);
        temp = "";
        for(int i = str.size()-1; i>=0;i--){
            (i != 0) ? temp+= str[i] + "." : temp+=str[i];
        }
        
        return temp;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends