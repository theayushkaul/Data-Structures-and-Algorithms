#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){

        int n=s.length();
        string ans="";

        for(int i=0;i<n;i++){
            
            if(s[i]>='a' && s[i]<='z' || isdigit(s[i])){
                ans+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                s[i]=tolower(s[i]);
                ans+=s[i];
            }
            else{
                continue;
            }
        }

        int l=0,e=ans.length()-1;

        while(l<=e){
            if(ans[l]==ans[e]){
                l++;
                e--;
            }
            else{
                return false;
            }
        }

        return true;

}

void revStr(string &s){
    int n=s.length();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
}

int main(){
    string str="A man, a plan, a canal: Panama";
    
    cout<<str<<endl;
    cout<<"Checking this string is Palindrome or not "<<endl;
    cout<<isPalindrome(str);
    return 0;
}
