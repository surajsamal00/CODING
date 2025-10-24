#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


template<typename T>
void print(T a) { //vector only
    for (auto x:a){
        cout << x << " ";
        // cout << setw(6) << x ;
    }
    cout << endl;
}

bool dfs(int node, vector<int>& path, vector<vector<int>>& adj, vector<int>& visited){
    visited[node] = 1;
    for(auto nbr : adj[node]){
        if(visited[nbr] == 2) continue;
        path.push_back(nbr);
        if(visited[nbr] == 0){
            if(dfs(nbr, path, adj, visited)){
                return true;
            }
        }
        else if(visited[nbr] == 1){
            return true;
        }
        path.pop_back();
    }
    visited[node] = 2;
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> visited(n+1,0);
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            vector<int> path{i};
            if(dfs(i, path, adj, visited)){
                int idx = 0;
                for(int j = 0; j < path.size(); j++){
                    if(path[j] == *path.rbegin()){
                        idx = j;
                        break;
                    }
                }
                path.erase(path.begin(), path.begin()+idx);
                cout << path.size() << endl;
                print(path);
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
