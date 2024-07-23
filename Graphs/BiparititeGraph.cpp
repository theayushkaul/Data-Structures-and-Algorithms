#include<bits/stdc++.h>
using namespace std;

// A Graph which can be colored using 2 colors such that no adjacent vertices have the same color.
// DFS
class Solution {
    bool solveDfs(vector<vector<int>>& graph, int node, vector<int>& color){
        bool ans = true;
        for(auto neighbour: graph[node]){
            if(color[neighbour] == -1){
                color[neighbour] = 1 - color[node];
                ans = ans && solveDfs(graph,neighbour,color);
            }else if(color[neighbour] == color[node]){
                return false;
            }
        }

        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        bool flag = true;

        for(int i=0; i<n;i++){
            if(color[i] == -1){
                color[i] = 0;
                flag = flag && solveDfs(graph,i,color);
                if(!flag){
                    return false;
                }
            }
        }

        return flag;
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 indicates that the node is not colored

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int point = q.front();
                    q.pop();

                    for (int neighbor : graph[point]) {
                        if (color[neighbor] == -1) {
                            // Color the neighbor with the opposite color
                            color[neighbor] = 1 - color[point];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[point]) {
                            // If the neighbor has the same color, it's not bipartite
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main(){

    return 0;
}