// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
using namespace std;

// Tells if a cycle is present in the directed graph using dfs
bool checkCycleDFS(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int>>& adj){
    // The current node is visited and dfsvisited
    visited[node] = 1;
    dfsVisited[node] = 1;

    // DFS
    for(auto neighbour: adj[node]){
        // If this neighbour of the node isn't visited then reccursive call for the current neighbour
      if(!visited[neighbour]){
        bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
        if(cycleDetected){
          return true;
        }
      }
    //   if the dfsvisited is true for this neighbour it means a cycle is present
      else if(dfsVisited[neighbour]){
          return true;
        }
    }
    // Backtrack
    dfsVisited[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Adjancy list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;

      adj[u].push_back(v);
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    for(int i = 1;i<=n;i++){
      if(!visited[i]){
        bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adj);
        if(cycleFound){
          return true;
        }
      }
    }

    return false;
}

int main(){

    return 0;
}