#include <bits/stdc++.h> 

void solve(vector<vector<int>> &m, int n,vector<string>& ans,int x,int y,vector<vector<bool>> visited,string path){
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

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    if(arr[0][0] == 0 || arr[n-1][n-1] == 0){
        return ans;
    }
    vector<vector<bool>> visited(n, vector<bool>(n,0) );
    string path = "";

    solve(arr,n,ans,0,0,visited,path);

    return ans;
}

