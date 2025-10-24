#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    indeg[0] = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    int idx = -1;
    queue<int> q;
    vector<int> topo;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto nbr : adj[node]){
            indeg[nbr]--;
            if(indeg[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    // print(topo);
    vector<int> dp(n+1, -1e18);
    vector<int> parent(n+1, -1);
    dp[1] = 0;
    for(auto node : topo){
        if(dp[node] == -1e18) continue;
        else{
            for(auto nbr : adj[node]){
                if(dp[nbr] < 1 + dp[node]){
                    dp[nbr] = 1 + dp[node];
                    parent[nbr] = node;
                }
            }
        }
    }

    if(dp[n] == -1e18){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> path;
        while(n != -1){
            path.push_back(n);
            n = parent[n];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        print(path);
    }


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