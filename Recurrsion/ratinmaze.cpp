#include <bits/stdc++.h>
using namespace std;

class Solution{
    void solve(vector<vector<int>> &m, int n,vector<string>& ans,int x,int y,vector<vector<int>> visited,string path){
        if(x==n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // down
        int newx = x+1 , newy = y;
        
        if(newx>=0 && newy>=0 && newx < n && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1 ){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        // left
        newx = x;
        newy = y-1;
        if(newx>=0 && newy>=0 && newx < n && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1 ){
            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        // right
        newy = y+1;
        if(newx>=0 && newy>=0 && newx < n && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1 ){
            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        // up
        newx = x-1;
        newy = y;
        if(newx>=0 && newy>=0 && newx < n && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1 ){
            path.push_back('U');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 0){
            return ans;
        }
        
        int srcx=0,srcy=0;
        
        vector<vector<int>> visited = m;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        solve(m,n,ans,srcx,srcy,visited,path);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends