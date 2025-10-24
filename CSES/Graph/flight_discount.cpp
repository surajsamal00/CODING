#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
using tiii = tuple<int, int, int>;

template<typename T>
void print(T a) { 
    for (auto x:a){
        for(auto y : x) cout << setw(4) << y << ":";
        cout << " ";
    }
    cout << endl;
}

signed main() {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<pair<int,int>>> adj(n+1);
    while(m--){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<vector<int>> dist(n+1, vector<int>(2,LLONG_MAX));
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    dist[1][0] = 0;
    dist[1][1] = 0;
    pq.push(make_tuple(0,0,1));
    // print(dist);
    while(!pq.empty()){
        auto [d, status, node] = pq.top();

        pq.pop();
        if(d != dist[node][status]) continue;

        for(auto next : adj[node]){
            auto [nbr, w] = next;
            int curr = w + d;
            if(dist[nbr][status] > curr){
                dist[nbr][status] = curr;
                pq.push(make_tuple(curr, status, nbr));
                // print(dist);
            }
        }

        if(status == 0){
            for(auto next : adj[node]){
                auto [nbr, w] = next;
                int curr = w/2 + d;
                if(dist[nbr][1] > curr){
                    dist[nbr][1] = curr;
                    pq.push(make_tuple(curr, 1, nbr));
                    // print(dist);
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]);
    return 0;
}
