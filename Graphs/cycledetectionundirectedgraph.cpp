#include<bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>> adj){
    // stores if the node is a parent node or not
    unordered_map<int,int> parent;
    // source is already visited and is a parent of some other nodes
    parent[src] = 1;
    visited[src] = 1;

    // BFS traversal
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            // if this node is visited and is not the parent of the front node then the cycle is present
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            // if this node isn't visited push the node in the quew
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]= 1;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

bool isCyclicDFS(int node,int parent,unordered_map<int,bool>& visited,unordered_map<int,list<int>> adj){
    visited[node] = 1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected =  isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetected){
                return true;
            }
            else if(neighbour != parent){
                return true;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list
    unordered_map<int,list<int>> adj;

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int,bool> visited;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            // bool ans = isCyclicDFS(i,-1,visited,adj);
            bool ans = isCyclicBFS(i,visited,adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }

    return "No"; 
}

int main(){

    return 0;
}