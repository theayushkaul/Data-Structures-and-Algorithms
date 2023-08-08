#include <bits/stdc++.h>
using namespace std;

string rev(string s){
    if(s.length()==1){
        return s;
    }
    string ans="";
    for(int i=0;i<s.length();i++){
        ans+=s[s.length()-i-1];
    }
    return ans;
}

int main() {
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
	    int n;
	    cin>>n;
	    
	    string bin;
	    cin>>bin;
	    
	    string str1="",str2="";
	    int j=0;

	    while(j<=n/2){
	            if(bin[j]=='0'){
	                str1+="0";
	            }
	            else{
	                str2+="1";
	            }

                if(str1.length()+str2.length()==n){
                    break;
                }

	            if(bin[n-j-1]=='0'){
	                str2+="0";
	            }
	            else{
	                str1+="1";
	            }

                if(str1.length()+str2.length()==n){
                    break;
                }
	        j++;
	    }
	    
	    cout<<rev(str1)+str2<<endl;
	}
	return 0;
}