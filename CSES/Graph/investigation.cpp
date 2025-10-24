#include <bits/stdc++.h>
using namespace std;
#define int long long

using tii = tuple <int,int>;
int mod = 1e9 + 7;
int inf = 1e18;

template<typename T>
void print(T a) { 
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}

void test_case(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    vector<int> dist(n+1, 1e18);
    vector<int> count(n+1,0);
    vector<int> mn(n+1,1e18);
    vector<int> mx(n+1,0);

    dist[1] = 0;
    count[1] = 1;
    mn[1] = 0;
    mx[1] = 0;

    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();
        if(d > dist[node]) continue;
        for(auto next : adj[node]){
            auto [nbr, w] = next;
            if(d+w <= dist[nbr]){
                int mini = mn[node] + 1, maxi = mx[node] + 1;
                if(d+w == dist[nbr]){
                    count[nbr] = (count[nbr] + count[node]) % mod;
                    mn[nbr] = min(mn[nbr], mini);
                    mx[nbr] = max(mx[nbr], maxi);
                }
                else{
                    dist[nbr] = d + w;
                    mn[nbr] = mini;
                    mx[nbr] = maxi;
                    count[nbr] = count[node];
                    pq.push({d+w, nbr});
                }
            }
        }
    }
    cout << dist[n] << " " << count[n] << " " << mn[n] << " " << mx[n] << endl;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while(T--){
        test_case();
    }
    return 0;
}