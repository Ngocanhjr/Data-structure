#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack <int> topo;
bool visited[1001];
vector<int> adj[1001];

void dfs(int u){
    visted[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    topo.push(u);
}