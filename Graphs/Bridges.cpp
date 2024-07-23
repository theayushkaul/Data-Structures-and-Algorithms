#include<bits/stdc++.h>
using namespace std;

/*
A bridge in any graph is defined as an edge which, when removed,
 makes the graph disconnected (or more precisely, 
increases the number of connected components in the graph).
*/

#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void dfs(unordered_map<int, list<int>>& adj, int parent, vector<int>& disc, vector<int>& low, int node, unordered_map<int, bool>& visited, int& timer, vector<vector<int>>& result) {
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (int neighbour : adj[node]) {
        if (neighbour == parent) {
            continue;
        }
        if (!visited[neighbour]) {
            dfs(adj, node, disc, low, neighbour, visited, timer, result);
            low[node] = min(low[node], low[neighbour]);
            if (low[neighbour] > disc[node]) {
                result.push_back({node, neighbour});
            }
        } else {
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            dfs(adj, -1, disc, low, i, visited, timer, result);
        }
    }
    return result;
}

int main(){

    return 0;
}