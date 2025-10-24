#include <bits/stdc++.h>
using namespace std;
#define int long long
using pi = pair<int, int>;


void print(vector<int>& v){
    for(auto x : v) cout << x << " ";
    cout << endl;
}
signed main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<int> pop(n+1,0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,1});
    vector<int> ans;
    while(!pq.empty()){
        auto [dist, node] = pq.top();
        pq.pop();
        if(pop[node]==k) continue;
        pop[node] += 1;
        if(node == n){
            ans.push_back(dist);
            if(pop[node]==k) break;
        }

        for(auto& [nbr, w] : adj[node]){
            if(pop[nbr] < k){
                pq.push({dist + w, nbr});
            }
        }
        
    }
    print(ans);
    return 0;
}
