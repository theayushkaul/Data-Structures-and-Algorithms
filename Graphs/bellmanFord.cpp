#include<bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // Relax edges (n-1) times
    for(int i = 1; i <= n - 1; ++i) {
        for(int j = 0; j < m; ++j) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;
    for(int j = 0; j < m; ++j) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle) {
        return -1;
    }

    return dist[dest] == 1e9 ? -1 : dist[dest];
}

int main(){

    return 0;
}