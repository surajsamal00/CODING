#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<long long, int>;
int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<ll> distance(n+1,LLONG_MAX);
    distance[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [dis, city] = pq.top();
        pq.pop();
        if (dis != distance[city]) continue; 
         
        for(auto next : adj[city]){
            auto [nbr, d] = next;
            if(distance[nbr] > dis + d){
                distance[nbr] = dis + d;
                pq.push({dis+d, nbr});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}
