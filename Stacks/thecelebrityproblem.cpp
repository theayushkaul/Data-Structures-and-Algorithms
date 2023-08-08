#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            
            int b= s.top();
            s.pop();
            
            if(M[a][b]==1){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        bool rowCheck=true;
        bool colCheck=true;
        
        for(int i=0;i<n;i++){
            if(s.top()==i){
                continue;
            }
            if(M[s.top()][i]==1){
                rowCheck=false;
            }
        }
        
        for(int i=0;i<n;i++){
            if(s.top()==i){
                continue;
            }
            if(M[i][s.top()]==0){
                colCheck=false;
            }
        }
        
        if(rowCheck && colCheck){
            return s.top();
        }
        else{
            return -1;
        }
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends