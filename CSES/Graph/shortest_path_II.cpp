#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<long long, int>;
int mod = 1e9 + 7;

template<typename T>
void print(T& v){
    for(auto& x : v){
        cout << x << "\n";
    }
    cout << endl;
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector dist(n+1, vector<ll>(n+1, 2e18));
    while(m--){
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(w, dist[u][v]);
        dist[v][u] = min(w, dist[v][u]);
    }
    

    //self dist
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    for(int via = 1; via <= n; via++){
        for(int from = 1; from <= n; from++){
            if(dist[from][via] == 2e18) continue;
            for(int to = 1; to <= n; to++){
                if(dist[via][to] == 2e18) continue;
                dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
            }
        }
    }
    vector<ll> ans;
    while(q--){
        int from, to;
        cin >> from >> to;
        ll d = dist[from][to];
        if(d == 2e18){
            d = -1;
        }
        ans.push_back(d);
    }
    print(ans);
    return 0;
}
