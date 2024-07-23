#include<bits/stdc++.h>
using namespace std;


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

int main(){
    int n;

    // Initializing two vectors
    vector<int> rank(n,0);
    vector<int> parent(n);
    for(int i=0; i<n;i++){
        parent[i] = i;
    }

    return 0;
}