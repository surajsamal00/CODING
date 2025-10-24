#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
 
bool flg = true;
void dfs(int node, int team, vector<vector<int>>& adj, vector<int>& colour){
    colour[node] = team;
    team = 3 - team;
    for(auto nbr : adj[node]){
        if(colour[nbr] == 0){
            dfs(nbr, team, adj, colour);
        }
        else if(colour[nbr] != team){
            flg = false;
            return;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colour(n+1,0);
    flg = true;
    for(int i = 1; i <= n; i++){
        if(colour[i] == 0){
            dfs(i, 1, adj, colour);
        }
    }
    if(flg){
        for(int i = 1; i <= n; i++){
            cout << colour[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}