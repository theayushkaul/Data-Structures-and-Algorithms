#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto edge: g){
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }


    // To Store distances
    vector<int> distances(n+1,INT_MAX);

    // Included in MST data structure
    vector<bool> mst(n+1,false);

    // Parent nodes
    vector<int> parent(n+1,-1);

    // Initialization: The first node won't get reached by any node
    distances[1] = 0;

    // Prims Algorithm
    // 1st. Get the node with minimum distance
    // 2nd. Iterate through neighbours and update if neighbour.second < distances[neighbour] 
    // and add the parent of neighbour to be the node.
    // So the parent node reaches node in distances[node] weight which is minimum weight
    
    // we can also use priority queue(minHeap) to get the min distance node in each iteration
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>> minHeap;  // (distance, node)



    for(int i=1; i<=n;i++){
        int node;
        int mini = INT_MAX;
        for(int k=1;k<=n;k++){
            if(!mst[k] && distances[k] < mini){
                node = k;
                mini = distances[k];
            }
        }

        mst[node] = true;
        for(auto neighbour : adj[node]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(!mst[v] && (w < distances[neighbour.first])){
                parent[v] = node;
                distances[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;

    for(int i = 2; i<= n; i++){
        result.push_back({{parent[i],i},distances[i]});
    }


    return result;
}
