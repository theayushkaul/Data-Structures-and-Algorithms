#include<bits/stdc++.h>
using namespace std;

// Using Disjoint Sets
#include<algorithm>
int findParent(vector<int>& parent, int node){

  if(parent[node] == node){
    return node;
  }
  
  // Path Compression
  return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
  u = findParent(parent,u);
  v = findParent(parent,v);

  if(rank[u] > rank[v]){
    parent[v] = u;
  }else if(rank[u] < rank[v]){
    parent[u] = v;
  }else{
    parent[u] = v;
    rank[v]++;
  }

}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  // Disjoint Sets
  // Initializing two vectors
  vector<int> rank(n,0);
  vector<int> parent(n);
  for(int i=0; i<n;i++){
    parent[i] = i;
  }

  // Kruskal Algorithm
  vector<pair<int, pair<int,int>>> e;
  for(auto edge: edges){
    e.push_back({edge[2],{edge[0],edge[1]}});
  }
  sort(e.begin(),e.end());

  int minWeight = 0;
  for(int i=0; i<e.size();i++){
    int u = findParent(parent, e[i].second.first);
    int v = findParent(parent,e[i].second.second);

    int wt = e[i].first;

    if(u != v){
      minWeight += wt;
      unionSet(u,v,parent,rank);
    }
  }

  return minWeight;
}
int main(){

    return 0;
}