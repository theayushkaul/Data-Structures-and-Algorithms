#include <vector>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;

// Function to perform topological sort
void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true; // Mark the current node as visited

    // Visit all the neighbors of the current node
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj); // Recursive call for the neighbor
        }
    }

    s.push(node); // Push the current node to the stack after visiting all its neighbors
}

// Depth-first search function
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    visited[node] = true; // Mark the current node as visited

    // Visit all the neighbors of the current node
    for (auto i : adjList[node]) {
        if (!visited[i]) {
            dfs(i, visited, adjList); // Recursive call for the neighbor
        }
    }
}

// Function to find the number of strongly connected components
int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // Create the adjacency list
    unordered_map<int, list<int>> adj;
    int e = edges.size();
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int d = edges[i][1];
        adj[u].push_back(d); // Add edge from u to d
    }

    // Perform topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++) {
        visited[i] = false; // Initialize visited map
    }
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj); // Call topoSort for every unvisited node
        }
    }

    // Create the transpose of the graph
    unordered_map<int, list<int>> transpose;
    unordered_map<int, bool> visitedMap;
    for (int i = 0; i < v; i++) {
        visitedMap[i] = false; // Reset visited map for the second DFS
        for (auto neighbour : adj[i]) {
            transpose[neighbour].push_back(i); // Reverse the direction of edges
        }
    }

    // Perform DFS according to the finish times in the stack
    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visitedMap[top]) {
            dfs(top, visitedMap, transpose); // Call DFS for every unvisited node in the transpose graph
            count++; // Increment the count of strongly connected components
        }
    }

    return count; // Return the number of strongly connected components
}
