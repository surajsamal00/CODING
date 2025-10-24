#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int N = 100007;
int timer, disc[N], low[N];
stack<int> stk;
bool instack[N];
vector<vector<int>> components;
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
        vector<int> curr;
        while(true){
            int v = stk.top();
            stk.pop();
            instack[v] = false;
            curr.push_back(v);
            if(v == node){
                break;
            }
        }
        components.push_back(curr);
    }
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    fill(disc, disc + n + 1, -1);
    fill(low, low + n + 1, -1);
    fill(instack, instack + n + 1, false);
    timer = 1;
    for(int i = 1; i <= n; i++){
        if(disc[i] == -1){
            tarjanSCC(i, adj);
        }
    }

    if(components.size() == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n" << components[0][0] << " " << components[1][0] << endl;
    }
    return 0;
}
