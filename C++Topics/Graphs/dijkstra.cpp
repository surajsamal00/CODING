#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;   // (distance, node)

const ll INF = 1e18;         // large enough for "infinity"

// important step in while loop to skip outdated nodes and not waste time updating nbrs based on obselete dist value
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // {neighbor, weight}
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // if the graph is undirected, add both ways
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // uncomment if undirected
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;  // source = 1

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;  // skip stale entry

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << " "; // unreachable
        else cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}
