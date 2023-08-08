#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,set<int>>& adjList,unordered_map<int,bool>& visited,vector<int>& ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // Store the frontNode in the vector
        ans.push_back(frontNode);
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    for(auto i: edges){
            adjList[i.first].insert(i.second);
            adjList[i.second].insert(i.first);
    }

    vector<int> ans;

    unordered_map<int,bool> visited;
    for(int i=0 ; i < vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }

    return ans;
}

int main(){

    return 0;
}