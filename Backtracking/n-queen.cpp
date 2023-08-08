#include<bits/stdc++.h>
using namespace std;

// The N-Queens puzzle is the problem of placing N chess queens on an N*N chessboard such that no two queens attack each other.

#include <bits/stdc++.h> 

void addSolution(vector<vector<int>>& ans,vector<vector<int>> board,int n){

    vector<int> temp;

    for(int i = 0;i<n ; i++){
        for(int j = 0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> board,int n){

    int x = row;
    int y = col;
// for the left row 
    while(y>=0){
        if(board[x][y]){
            return false;
        }
        y--;
    }

    // For diagonals on the left
    y = col;

    while(x>=0 && y>= 0){
        if(board[x][y]){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;


    while(x<n && y>= 0){
        if(board[x][y]){
            return false;
        }
        x++;
        y--;
    }

    // It means there is no queen present in this queens way
    return true;
}

void solve(int col,vector<vector<int>>& ans,vector<vector<int>>& board,int n){
    // base case
    if(col == n){
        addSolution(ans,board,n);
        return;
    }

    for(int row = 0; row<n; row++){
        if(isSafe(row,col,board,n)){
            // place the queen
            board[row][col] = 1;
            solve(col+1,ans,board,n);
            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ans,board,n);

    return ans;
}

int main(){

    return 0;
}