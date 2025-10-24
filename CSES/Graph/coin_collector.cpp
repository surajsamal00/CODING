#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int timer, curr_id, desc[100009], low[100009], scc_id[100009];
stack<int> stk;
bool instack[100009];

//dfs over condensation graphs
template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
        // cout << setw(20) << x ;
    }
    cout << endl;
}

void tarjanSCC(int node, vector<vector<int>>& adj){
    desc[node] = low[node] = timer++;
    stk.push(node);
    instack[node] = true;

    for(auto nbr : adj[node]){
        if(desc[nbr] == -1){
            tarjanSCC(nbr, adj);
            low[node] = min(low[node], low[nbr]);
        }
        else if(instack[nbr]){
            low[node] = min(low[node], desc[nbr]);
        }
    }

    if(desc[node] == low[node]){
        while(true){
            int v = stk.top();
            stk.pop();
            instack[v] = false;
            scc_id[v] = curr_id;
            if(v == node){
                break;
            }
        }
        curr_id++;
    }
}

int cond_dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& coins){
    int root = coins[node];
    int mx_child = 0;
    for(auto nbr : adj[node]){
        int child = 0;
        if(visited[nbr] == -1){
            child = cond_dfs(nbr, adj, visited, coins);
        }
        else{
            child = visited[nbr];
        }
        mx_child = max(child, mx_child);
    }

    return visited[node] = (root + mx_child);
}

signed main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> coins(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    fill(desc, desc + n + 1, -1);
    fill(low, low + n + 1, -1);
    fill(instack, instack + n + 1, false);
    fill(scc_id, scc_id + n + 1, -1);

    timer = 1;
    curr_id = 1;
    for(int i = 1; i <= n; i++){
        if(desc[i] == -1){
            tarjanSCC(i, adj);
        }
    }
    vector<vector<int>> cond_adj(curr_id);
    vector<int> cond_coins(curr_id, 0);
    for(int i = 1; i <= n; i++){
        cond_coins[scc_id[i]] += coins[i];
    }

    for(int i = 1; i <= n; i++){
        for(auto nbr : adj[i]){
            if(scc_id[i] != scc_id[nbr]){
                cond_adj[scc_id[i]].push_back(scc_id[nbr]);
            }
        }
    }

    vector<int> visited(curr_id, -1);
    int start = curr_id - 1;
    int mx = 0;
    for(int i = start; i > 0; i--){
        if(visited[i] == -1){
            mx = max(mx, cond_dfs(i, cond_adj, visited, cond_coins));
        }
    }
    cout << mx << endl;

    return 0;
}
