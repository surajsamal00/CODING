#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

struct DSU{
    int n;
    vector<int> parent, rank, size;
    DSU(int n) : n(n), parent(n+1), rank(n+1,1), size(n+1,1){
        iota(parent.begin(), parent.end(),0);
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }

    void union_r(int u, int v){
        int pu = findParent(u), pv = findParent(v);
        if(pu == pv) return;
        else if(rank[pu] == rank[pv]){
            parent[pv] = pu;
            rank[pu]++;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
        }
    }

    void union_s(int u, int v){
        int pu = findParent(u), pv = findParent(v);
        if(pu == pv) return;
        else if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
signed main() {
    int n, m, a, b, c;
    cin >> n >> m;
    DSU network = DSU(n);
    vector<vector<int>> edges;
    while(m--){
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());
    int res = 0;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][1], v = edges[i][2], w = edges[i][0];
        if(network.findParent(u) != network.findParent(v)){
            res += w;
            network.union_s(u, v);
        }
        
    }
    int p = network.findParent(1);
    for(int i = 1; i <= n; i++){
        if(network.findParent(i) != p){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}
