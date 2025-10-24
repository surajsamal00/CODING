#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}

bool dfs(int node, vector<int>& path, vector<int>& visited, vector<vector<int>>& adj){
    visited[node] = 1;
    for(auto nbr : adj[node]){
        if(visited[nbr]==1){
            return false;
        }
        else if(visited[nbr]==0 && !dfs(nbr, path, visited, adj)){
            return false;
        }
    }
    visited[node] = 2;
    path.push_back(node);
    return true;
}
signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> path;
    vector<int> visited(n+1,0);
    bool flg = true;
    for(int i = 1; i <= n && flg; i++){
        if(visited[i]==0){
            if(!dfs(i, path, visited, adj)){
                flg = false;
                break;
            }
        }
    }
    if(flg){
        reverse(path.begin(), path.end());
        print(path);
    }
    else{
        cout << "IMPOSSIBLE\n";
    }

}
