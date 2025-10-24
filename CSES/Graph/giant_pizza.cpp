#include <bits/stdc++.h>
using namespace std;

const int N = 200007;
int timer, disc[N], low[N], comp[N], sccid;
stack<int> stk;
bool instack[N];

void tarjanSCC(int node, vector<vector<int>>& adj){
    disc[node] = low[node] = timer++;
    stk.push(node);
    instack[node] = true;

    for(auto nbr : adj[node]){
        if(disc[nbr] == -1){
            tarjanSCC(nbr, adj);
            low[node] = min(low[node], low[nbr]);
        }
        else if(instack[nbr]){
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if(disc[node] == low[node]){
        while(true){
            int v = stk.top(); stk.pop();
            instack[v] = false;
            comp[v] = sccid;   // assign SCC ID here
            if(v == node) break;
        }
        sccid++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(2*m+1);

    for(int i = 0; i < n; i++){
        char c1, c2;
        int u, v;
        cin >> c1 >> u >> c2 >> v;

        bool flg1 = (c1 == '+'), flg2 = (c2 == '+');

        if(flg1 && flg2){          // ++
            adj[u+m].push_back(v);
            adj[v+m].push_back(u);
        }
        else if(flg1 && !flg2){    // +-
            adj[u+m].push_back(v+m);
            adj[v].push_back(u);
        }
        else if(!flg1 && flg2){    // -+
            adj[u].push_back(v);
            adj[v+m].push_back(u+m);
        }
        else{                       // --
            adj[u].push_back(v+m);
            adj[v].push_back(u+m);
        }
    }

    fill(disc, disc + 2*m + 2, -1);
    fill(low, disc + 2*m + 2, -1);
    fill(instack, instack + 2*m + 2, false);
    fill(comp, comp + 2*m + 2, 0);

    timer = 1;
    sccid = 1;
    for(int i = 1; i <= 2*m; i++){
        if(disc[i] == -1) tarjanSCC(i, adj);
    }

    string res(m, '+');
    for(int i = 1; i <= m; i++){
        if(comp[i] == comp[i+m]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        else if(comp[i] < comp[i+m]){ 
            res[i-1] = '+';
        }
        else{
            res[i-1] = '-';
        }
    }

    cout << res << "\n";
    return 0;
}
