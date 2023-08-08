#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    map<int,list<int>> adj;
    // create adj list
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // push the 0 indegree waale
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // BFS
    vector<int> ans;
    while(!q.empty()){
        int front  = q.front();
        q.pop();

        // store ans
        ans.push_back(front);

        // neighbour indegree updation
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
            q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){

    return 0;
}