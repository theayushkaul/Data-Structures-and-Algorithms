#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str,int s,int e){
    if(s>=e){
        return 1;
    }
    if(str[s]==str[e]){
        s++;
        e--;
        return checkPalindrome(str,s,e);
    }
    return 0;
}

int main(){
    string str="ba";
    checkPalindrome(str,0,str.length()-1) ? cout<<"It is a Palindrome"  : cout<<"It is not a Palindrome";
    cout<<endl;
    return 0;
}