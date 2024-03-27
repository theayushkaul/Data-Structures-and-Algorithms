#include <bits/stdc++.h>
using namespace std;
// Kahn's Algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Adj map
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    // Indegree array
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    // Push 0 indegree in the queue
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs traversal
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        // Add the frontNode to the answer
        ans.push_back(frontNode);

        for (auto neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            // When the indegree is 0 only then push to the queue
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}