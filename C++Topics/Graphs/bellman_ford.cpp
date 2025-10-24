#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

/* 
DONOT USE THIS AS IT IS TO FIND WHETHER PATH WILL REMAIN SAME BETWEEN TWO NODES OR NOT
There is a catch while bellman ford's final step can check for the negative cycle
ultimately it will exactly check for that only. If the negative cycle is in a different branch 
and the graph is directed the points on other branches won't get affected distance b/w them
will remain same. for that you have to run another dfs for all the cycle nodes and check 
whether your nodes are reachable from that dfs calls in forward path.
*/
bool bellmanFord(int n, int src, vector<Edge>& edges, vector<long long>& dist) {
    dist.assign(n, LLONG_MAX);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &e : edges) {
        if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
            return false; // Negative cycle detected
        }
    }

    return true; // No negative cycle
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist;
    int src = 0; // source vertex
    if (bellmanFord(n, src, edges, dist)) {
        for (int i = 0; i < n; i++) {
            if (dist[i] == LLONG_MAX) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "Negative cycle detected!\n";
    }
}
