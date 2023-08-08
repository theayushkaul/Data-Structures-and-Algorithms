#include<bits/stdc++.h>
using namespace std;

// Using Kahn's Algorithm
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  map<int,list<int>> adj;
    // create adj list
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(n);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // push the 0 indegree waale
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // BFS
    int count = 0;
    while(!q.empty()){
        int front  = q.front();
        q.pop();

        // increment count
        count++;

        // neighbour indegree updation
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
            q.push(neighbour);
            }
        }
    }
    if(count == n){
      return 0;
    }
    else{
      return 1;
    }
}

int main(){

    return 0;
}