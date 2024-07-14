#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // Initiallize distances with infinty
    vector<int> distances(vertices);
    for(int i=0;i<vertices;i++){
        distances[i] = INT_MAX;
    }

    // Creation of set on the basis of (distance,node)
    set<pair<int,int>> st;

    // The distance of source node will be zero from itself
    distances[source] = 0;
    st.insert(make_pair(0,source));

    // Traversing the nodes so that we can get shortest distance from the source node to every other node in the graph
    while(!st.empty()){

        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour: adj[topNode]){
            if(nodeDistance+neighbour.second<distances[neighbour.first]){
                auto record = st.find(make_pair(distances[neighbour.first],neighbour.first));

                if( record !=st.end()){
                    st.erase(record);
                }

                distances[neighbour.first] = nodeDistance+neighbour.second;
                st.insert(make_pair(distances[neighbour.first],neighbour.first));
            }
        }
    }
    return distances;
}


int main(){

    return 0;
}