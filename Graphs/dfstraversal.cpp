#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,set<int>>& adjList,unordered_map<int,bool>& visited,vector<int>& component,int node)
{
    component.push_back(node);
    visited[node]=1;
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList,visited,component,i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int vertex, int e, vector<vector<int>> &edges)
{
    unordered_map<int,set<int>> adjList;
    for(int i=0;i < edges.size();i++){
            adjList[edges[i][0]].insert(edges[i][1]);
            adjList[edges[i][1]].insert(edges[i][0]);
    }

    vector<vector<int>> ans;

    unordered_map<int,bool> visited;
    for(int i=0 ; i < vertex;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adjList,visited,component,i);
            ans.push_back(component);
        }
    }

    return ans;
}
int main(){

    return 0;
}