#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5;
vector<int> adj[N];
int timer, low[N], disc[N];
bool inStack[N];
stack<int> stk;

vector<vector<int>> components;

void tarjanSCC(int node) {
    disc[node] = low[node] = timer++;
    stk.push(node);
    inStack[node] = true;

    for (auto nbr : adj[node]) {
        if (disc[nbr] == -1) { // unvisited
            tarjanSCC(nbr);
            low[node] = min(low[node], low[nbr]); // lowest time the child can reach;
        } 
        else if (inStack[nbr]) { // back edge
            low[node] = min(low[node], disc[nbr]); 
            // easy to read makes sense as low is variable so comparing with disc which is const;
            // low will be lowest (pre-order assignment of low & disc) so no error but first thing makes sense.
        }
    }

    // head node found
    if (disc[node] == low[node]) {
        vector<int> curr;
        while (true) {
            int v = stk.top();
            stk.pop();
            inStack[v] = false;
            curr.push_back(v);
            if (v == node) break;
        }
        components.push_back(curr);
    }
}

int main() {
    int n, m;
    cin >> n >> m; // number of nodes, edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    fill(disc, disc + n, -1);
    fill(low, low + n, -1);
    fill(inStack, inStack + n, false);
    timer = 1;

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            tarjanSCC(i);
        }
    }

    // Print SCCs
    for (auto &comp : components) {
        for (int node : comp) cout << node << " ";
        cout << "\n";
    }
}
