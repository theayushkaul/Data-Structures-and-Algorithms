#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    void solve(string digits,string output,vector<string>& ans,string data[],int index){
        
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        // The number is a digit from the numerical string
        int number= digits[index]-'0';

        // String mapped to the digit in the phone keypad
        string value = data[number];
        
        for(int i=0;i<value.length();i++){
            output+=value[i];
            solve(digits,output,ans,data,index+1);
            output.pop_back();
        }
    }
    public:
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        string output;

        if(digits.length()==0){
            return ans;
        }
        // Mapping of digits to strings as shown in the phone keypad 
        string data[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits,output,ans,data,0);
        return ans;
    }
};