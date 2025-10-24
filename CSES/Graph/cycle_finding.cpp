#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
 
template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
        // cout << setw(20) << x ;
    }
    cout << endl;
}
 
signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<tuple<int, int , int>> edges;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
        adj[u].push_back({v, w});
    }
    vector<int> dist(n+1, 0);
    vector<int> parent(n+1,-1);
    int idx = -1;
    for(int t = 1; t <= n; t++){
        idx = -1; // idx set to null; in last step if remains null then no neg cycle
        for(int i = 0; i < edges.size(); i++){
            auto [u, v, w] = edges[i];
            if(dist[v] > dist[u] + w){
                idx = u;
                parent[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }
    
    
 
    if(idx==-1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        // backtrack n steps to ensure idx is inside cycle
        for (int i = 0; i < n; i++) idx = parent[idx];
        vector<int> cycle;
        int cur = idx;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != idx);
        cycle.push_back(idx);

        reverse(cycle.begin(), cycle.end());
        print(cycle);
    }
    
 
    return 0;
}