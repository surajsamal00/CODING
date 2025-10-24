#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int dist[100007];
int pre[100007];

template<typename T>
void print(T a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, 0x3f, sizeof(dist));

    dist[1] = 0;
    pre[1] = -1;

    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        auto[node, d] = q.front();
        q.pop();
        if(node == n){
            break;
        }
        d++;
        for(auto nbr : adj[node]){
            if(dist[nbr] > d){
                dist[nbr] = d;
                pre[nbr] = node;
                q.push({nbr, d});
            }
        }
    }

    if(dist[n] > 1e9){
        cout << "IMPOSSIBLE";
    }
    else {
        int node = n;
        vector<int> path;
        while(node != -1){
            path.push_back(node);
            node = pre[node];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        print(path);
    }
}