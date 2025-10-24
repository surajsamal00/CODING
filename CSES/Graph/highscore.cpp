#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
using ll = long long;


template<typename T>
void print(T v){
    for(auto x : v) cout << x << " ";
    cout << endl;
}

bool dfs(int node, int n, vector<bool>& visited, vector<vector<int>>& adj){
    if(node == n){
        return true;
    }
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            visited[nbr] = true;
            if(dfs(nbr, n, visited, adj)) return true;
        }
    }
    return false;
}
int main() {
    //we can use bellman ford
    int n, m;
    cin >> n >> m;
    vector<ll> dist(n+1, -2e18);
    dist[1] = 0;
    vector<tuple<int, int, int>> edges(m+1);
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(u, v, w);
        adj[u].push_back(v);
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            auto [u, v, w] = edges[j];
            if(dist[u] == -2e18) continue;
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    ll ans = dist[n];
    vector<int> nodes;
    for(int j = 1; j <= m; j++){
        auto [u, v, w] = edges[j];
        if(dist[u] == -2e18) continue;
        if(dist[v] < dist[u] + w){
            nodes.push_back(u);
        }
        dist[v] = max(dist[v], dist[u] + w);
    }
    vector<bool> visited(n+1, false);
    for(int i = 0; i < nodes.size(); i++){
        if(visited[nodes[i]]==false){
            visited[nodes[i]] = true;
            if(dfs(nodes[i], n, visited, adj)){
                ans = -1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
